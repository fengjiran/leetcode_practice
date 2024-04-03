//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace TIPS {

class People {
    std::string name_;
public:
//    People(std::string name) : name_(std::move(name)) {
//        std::cout << "move ctor\n";
//    }

    People(const std::string& name) : name_(name) {
        std::cout << "copy ctor\n";
    }
};

struct A {
    bool a;
    float b;
    double c;
};

void typeidTest() {
    std::cout << "int type: " << typeid(int).name() << std::endl
              << "unsigned type: " << typeid(unsigned).name() << std::endl
              << "long type: " << typeid(long).name() << std::endl
              << "unsigned long type: " << typeid(unsigned long).name() << std::endl
              << "char type: " << typeid(char).name() << std::endl
              << sizeof(A) << std::endl;

    People a("Alice");
    std::string bn = "Bob";
    People bb(bn);
}

}// namespace TIPS

TEST(Tips, typeid) {
    TIPS::typeidTest();
    int a = 5;
//    int&& ref = a;
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