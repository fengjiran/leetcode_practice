//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace TIPS {
class Base {
    virtual void f() {}
};

class Derived : public Base {};

void typeidTest() {
    Base b;
    Base* pb = nullptr;
    Derived d;

    std::cout << "int type: " << typeid(int).name() << std::endl
              << "unsigned type: " << typeid(unsigned).name() << std::endl
              << "long type: " << typeid(long).name() << std::endl
              << "unsigned long type: " << typeid(unsigned long).name() << std::endl
              << "char type: " << typeid(char).name() << std::endl;
}

class TypeidTest {
public:
    //
};
}// namespace TIPS

TEST(Tips, typeid) {
    TIPS::typeidTest();
    int a;
    int b;
    EXPECT_TRUE(typeid(a) == typeid(b));
}