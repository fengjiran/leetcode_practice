//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace TIPS {
class Base {
public:
    virtual void f() {
        std::cout << "Base class.\n";
    }
    virtual ~Base() = default;
};

class Derived1 : public Base {
public:
    void f() override {
        std::cout<< "Derived1 class.\n";
    }
};

class Derived2 : public Derived1 {
    //
};

struct A {
    bool a;
    float b;
    double c;
};

void typeidTest() {
    Base b;
    Base* pb = nullptr;
    Derived1 d;

    std::cout << "int type: " << typeid(int).name() << std::endl
              << "unsigned type: " << typeid(unsigned).name() << std::endl
              << "long type: " << typeid(long).name() << std::endl
              << "unsigned long type: " << typeid(unsigned long).name() << std::endl
              << "char type: " << typeid(char).name() << std::endl
              << sizeof(A) << std::endl;

    Base* p = new Derived2;
    p->f();
    delete p;
}

}// namespace TIPS

TEST(Tips, typeid) {
    TIPS::typeidTest();
    int a;
    int b;
    EXPECT_TRUE(typeid(a) == typeid(b));
}