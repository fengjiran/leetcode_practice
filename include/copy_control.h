//
// Created by 赵丹 on 2024/4/1.
//

#ifndef LEETCODE_PRACTICE_COPY_CONTROL_H
#define LEETCODE_PRACTICE_COPY_CONTROL_H

namespace CopyControlTest {
class HasPtr {
public:
    explicit HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr& rhs) {
        ps = new std::string(*rhs.ps);
        i = rhs.i;
    }

    HasPtr& operator=(const HasPtr& rhs) {
        if (this != &rhs) {
            auto newps = new std::string(*rhs.ps);
            delete ps;
            ps = newps;
            i = rhs.i;
        }
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

private:
    std::string* ps;
    int i;
};
}// namespace CopyControlTest

#endif//LEETCODE_PRACTICE_COPY_CONTROL_H
