//
// Created by fengj on 2024/5/28.
//
#include "utils.h"

class A {
    const int a;
public:
    A() : a(10) {}
    int get() const {
        return a;
    }

    explicit A(int i) : a(i) {}
};

class B {
    static const int a;
public:
    static int get() {
        return a;
    }
};

const int B::a = 10;

TEST(ConstTest, test1) {
    A tmp1;
    A tmp2(20);

    std::cout << tmp1.get() << std::endl;
    std::cout << tmp2.get() << std::endl;
    std::cout << B::get() << std::endl;
}