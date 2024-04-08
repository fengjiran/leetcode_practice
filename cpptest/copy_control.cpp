//
// Created by 赵丹 on 2024/4/1.
//
#include "copy_control.h"

namespace CopyControlTest {
HasPtrLikePointer& HasPtrLikePointer::operator=(const CopyControlTest::HasPtrLikePointer& rhs) {
    if (this != &rhs) {
        ++*rhs.cnt;
        if (--*cnt == 0) {
            delete ps;
            delete cnt;
        }
        ps = rhs.ps;
        i = rhs.i;
        cnt = rhs.cnt;
    }
    return *this;
}

HasPtrLikePointer::~HasPtrLikePointer() {
    if (--*cnt == 0) {
        delete ps;
        delete cnt;
    }
}

void StrVec::push_back(const std::string& s) {
    CheckAndAlloc();
    strAllocator::construct(alloc, firstFree++, s);
}

void StrVec::reallocate() {
    size_t newcap = size() != 0 ? 2 * size() : 1;
    auto newdata = strAllocator::allocate(alloc, newcap);
    auto src = start;
    auto dst = newdata;
    for (size_t i = 0; i < size(); ++i) {
        strAllocator::construct(alloc, dst, std::move(*src));
        ++dst;
        ++src;
    }
    free();
    start = newdata;
    firstFree = dst;
    cap = start + newcap;
}

void StrVec::reallocate(size_t newCap) {
    auto newdata = strAllocator::allocate(alloc, newCap);
    auto src = start;
    auto dst = newdata;
    for (size_t i = 0; i < size(); ++i) {
        strAllocator::construct(alloc, dst, std::move(*src));
        ++dst;
        ++src;
    }
    free();
    start = newdata;
    firstFree = dst;
    cap = start + newCap;
}

void StrVec::reserve(size_t n) {
    if (n > capacity()) {
        reallocate(n);
    }
}

void StrVec::free() {
    if (start) {
        auto p = firstFree;
        while (p != start) {
            strAllocator::destroy(alloc, --p);
        }
        strAllocator::deallocate(alloc, start, cap - start);
    }
}

std::pair<std::string*, std::string*> StrVec::AllocNCopy(const std::string* b, const std::string* e) {
    auto data = strAllocator::allocate(alloc, e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec& rhs) {
    auto newdata = AllocNCopy(rhs.begin(), rhs.end());
    start = newdata.first;
    firstFree = newdata.second;
    cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
    if (this != &rhs) {
        auto newdata = AllocNCopy(rhs.begin(), rhs.end());
        free();
        start = newdata.first;
        firstFree = newdata.second;
        cap = newdata.second;
    }
    return *this;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    auto newdata = AllocNCopy(il.begin(), il.end());
    start = newdata.first;
    firstFree = newdata.second;
    cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

TEST(CopyControlTest, test1) {
    std::cout << "\ncopy control test1:\n";
    StrVec vec;
    ASSERT_EQ(vec.size(), 0);
    ASSERT_EQ(vec.capacity(), 0);

    vec.push_back("abc");
    ASSERT_EQ(vec.size(), 1);
    ASSERT_EQ(vec.capacity(), 1);

    vec.push_back("def");
    ASSERT_EQ(vec.size(), 2);
    ASSERT_EQ(vec.capacity(), 2);

    vec.push_back("ghi");
    ASSERT_EQ(vec.size(), 3);
    ASSERT_EQ(vec.capacity(), 4);

    for (auto& it: vec) {
        std::cout << it << std::endl;
    }
}

TEST(CopyControlTest, test2) {
    std::cout << "\ncopy control test2:\n";
    StrVec vec {"abc", "def", "qaz"};
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec.capacity(), 3);
}

}// namespace CopyControlTest
