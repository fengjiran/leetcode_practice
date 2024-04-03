//
// Created by richard on 4/3/24.
//
#include "utils.h"

namespace VirtualFuncTest {
class Base {
public:
    virtual void func1() {
        std::cout << "Base class func1.\n";
    }
    virtual ~Base() = default;

private:
    int a{0};
};

class Derived1 : public Base {
public:
    void func1() override {
        std::cout << "Derived1 class func1.\n";
    }
};

class Derived2 : public Derived1 {
public:
    void func1() override {
        std::cout << "Derived2 class func.\n";
    }
};

TEST(VirtualFuncTest, test1) {
    Base* p = new Derived1();
    p->func1();
    delete p;
}
}