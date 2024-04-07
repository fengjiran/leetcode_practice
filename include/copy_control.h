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

private:
    void free();

private:
    static std::allocator<std::string> alloc;
    std::string* element;
    std::string* cap;
    std::string* firstFree;
};
}// namespace CopyControlTest

#endif//LEETCODE_PRACTICE_COPY_CONTROL_H
