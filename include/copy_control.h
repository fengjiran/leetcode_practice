//
// Created by 赵丹 on 2024/4/1.
//

#ifndef LEETCODE_PRACTICE_COPY_CONTROL_H
#define LEETCODE_PRACTICE_COPY_CONTROL_H
#include "utils.h"

namespace CopyControlTest {
class HasPtrLikeValue {
public:
    explicit HasPtrLikeValue(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtrLikeValue(const HasPtrLikeValue& rhs) {
        ps = new std::string(*rhs.ps);
        i = rhs.i;
    }

    HasPtrLikeValue& operator=(const HasPtrLikeValue& rhs) {
        if (this != &rhs) {
            auto newps = new std::string(*rhs.ps);
            delete ps;
            ps = newps;
            i = rhs.i;
        }
        return *this;
    }

    ~HasPtrLikeValue() {
        delete ps;
    }

private:
    std::string* ps;
    int i;
};

class HasPtrLikePointer {
public:
    explicit HasPtrLikePointer(const std::string& s = std::string())
        : ps(new std::string(s)), i(0), cnt(new size_t(1)) {}

    HasPtrLikePointer(const HasPtrLikePointer& rhs) : ps(rhs.ps), i(rhs.i), cnt(rhs.cnt) {
        ++*cnt;
    }

    HasPtrLikePointer& operator=(const HasPtrLikePointer& rhs);
    ~HasPtrLikePointer();

private:
    std::string* ps;
    int i;
    size_t* cnt;
};

class StrVec {
public:
    StrVec() : start(nullptr), cap(nullptr), firstFree(nullptr) {}
    StrVec(std::initializer_list<std::string> il);
    explicit StrVec(size_t n);
    StrVec(size_t n, const std::string&);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);

    void push_back(const std::string&);
    size_t size() const { return firstFree - start; }
    size_t capacity() const { return cap - start; }
    std::string* begin() const { return start; }
    std::string* end() const { return firstFree; }
    std::pair<std::string*, std::string*> AllocNCopy(const std::string* b, const std::string* e);
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const std::string& s);

    ~StrVec();

private:
    void reallocate();
    void reallocate(size_t newCap);
    void free();
    void CheckAndAlloc() {
        if (firstFree == cap) {
            reallocate();
        }
    }

private:
    using strAllocator = std::allocator_traits<std::allocator<std::string>>;
    std::allocator<std::string> alloc;
    std::string* start;
    std::string* cap;
    std::string* firstFree;
};
}// namespace CopyControlTest

#endif//LEETCODE_PRACTICE_COPY_CONTROL_H
