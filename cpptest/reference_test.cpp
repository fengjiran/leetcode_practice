//
// Created by richard on 3/24/24.
//
#include "utils.h"

namespace RefTest {
void change(int&& ref) {
    ref = 8;
}

class Array {
public:
    Array() : m_data(nullptr), m_size(0) {}
    explicit Array(int size) : m_size(size) {
        m_data = new int[size];
    }

    // copy ctor
    Array(const Array& rhs) {
        std::cout << "Copy Constructor.\n";
        m_size = rhs.m_size;
        m_data = new int[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = rhs.m_data[i];
        }
    }

    // move ctor
    Array(Array&& rhs) noexcept {
        std::cout << "Move Constructor.\n";
        m_data = rhs.m_data;
        m_size = rhs.m_size;
        rhs.m_data = nullptr;
        rhs.m_size = 0;
    }

    // copy assignment
    Array& operator=(const Array& rhs) {
        std::cout << "Copy Assignment.\n";
        if (this != &rhs) {
            delete[] m_data;
            m_size = rhs.m_size;
            m_data = new int[m_size];
            for (int i = 0; i < m_size; ++i) {
                m_data[i] = rhs.m_data[i];
            }
        }
        return *this;
    }

    // move assignment
    Array& operator=(Array&& rhs) noexcept {
        std::cout << "Move Assignment.\n";
        if (this != &rhs) {
            delete[] m_data;
            m_data = rhs.m_data;
            m_size = rhs.m_size;
            rhs.m_data = nullptr;
            rhs.m_size = 0;
        }
        return *this;
    }

    ~Array() {
        delete[] m_data;
    }

private:
    int m_size;
    int* m_data;
};

TEST(RefTest, test1) {
    int a = 5;
    int& leftRef = a;
    int&& rightRef = std::move(a);

    //    RefTest::change(a);  // 编译不过，a是左值，change参数要求右值
    //    RefTest::change(leftRef);  // 编译不过，左值引用ref_a_left本身也是个左值
    //    RefTest::change(rightRef); // 编译不过，右值引用ref_a_right本身也是个左值

    change(std::move(a));
    change(std::move(leftRef));
    change(std::move(rightRef));

    change(5);

    std::cout << "Print address:\n";
    std::cout << "var: " << &a << std::endl;
    std::cout << "left ref: " << &leftRef << std::endl;
    std::cout << "right ref: " << &rightRef << std::endl;
    EXPECT_EQ(&a, &leftRef);
    EXPECT_EQ(&a, &rightRef);
    ASSERT_EQ(&a, &leftRef);
    ASSERT_EQ(&a, &rightRef);
}

TEST(RefTest, test2) {
    Array a;
//    Array b(std::move(a));
    Array c = std::move(a);
}

}// namespace RefTest
