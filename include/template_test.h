//
// Created by richard on 3/25/24.
//

#ifndef LEETCODE_PRACTICE_TEMPLATE_TEST_H
#define LEETCODE_PRACTICE_TEMPLATE_TEST_H
#include "utils.h"

namespace TemplateTest {

template<typename T>
T myMax(const T& x, const T& y) {
    return x > y ? x : y;
}

template<typename T>
class Blob {
public:
    //    typedef T value_type;
    //    typedef typename std::vector<T>::size_type size_type;
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    // constructor
    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }

    bool empty() { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }

    void push_back(T&& t) { data->push_back(std::move(t)); }

    void pop_back();

    T& front();

    T& back();

    T& operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const;
};


}// namespace TemplateTest

#endif//LEETCODE_PRACTICE_TEMPLATE_TEST_H
