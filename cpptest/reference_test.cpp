//
// Created by richard on 3/24/24.
//
#include "utils.h"

namespace RefTest {
void change(int&& ref) {
    ref = 8;
}
}// namespace RefTest

TEST(RefTest, test1) {
    int a = 5;
    int& leftRef = a;
    int&& rightRef = std::move(a);

    //    RefTest::change(a);  // 编译不过，a是左值，change参数要求右值
    //    RefTest::change(leftRef);  // 编译不过，左值引用ref_a_left本身也是个左值
    //    RefTest::change(rightRef); // 编译不过，右值引用ref_a_right本身也是个左值

    RefTest::change(std::move(a));
    RefTest::change(std::move(leftRef));
    RefTest::change(std::move(rightRef));

    RefTest::change(5);

    std::cout << "Print address:\n";
    std::cout << "var: " << &a << std::endl;
    std::cout << "left ref: " << &leftRef << std::endl;
    std::cout << "right ref: " << &rightRef << std::endl;
}
