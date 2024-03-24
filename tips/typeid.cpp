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

    void f1() {
        std::cout << "Base class\n";
        int b = 1;
        f2(b + 1);
    }

    void f2(const int& a) {
        std::cout << a << std::endl;
    }

protected:
    int a{0};
};

class Derived1 : public Base {
public:
    void f() override {
        std::cout << "Derived1 class.\n";
        std::cout << a;
    }

    void f1() {
        std::cout << "derived1 class\n";
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

    Base* p = new Derived1;
    p->f1();
    delete p;
}

}// namespace TIPS

TEST(Tips, typeid) {
    TIPS::typeidTest();
    int a = 5;
    int&& ref = std::move(a);
    int b = a;
    std::cout << a << std::endl;
    EXPECT_TRUE(typeid(a) == typeid(b));
    static char* s[] = {"black", "white", "yellow", "violet"};
    char **ptr[] = {s + 3, s + 2, s + 1, s}, ***p = ptr;
    **++p;
    std::cout << *++*++p + 3 << std::endl;

    std::unordered_map<std::string, int> map1{
            {"ab", 1},
            {"cd", 2},
            {"ef", 3}};

    std::unordered_map<std::string, int> map2{
            {"cd", 2},
            {"ef", 3},
            {"ab", 1}};

    std::cout << std::boolalpha << std::equal(map1.begin(), map1.end(), map2.begin(), map2.end()) << std::endl;
    std::cout << std::boolalpha << (map1 == map2) << std::endl;
}