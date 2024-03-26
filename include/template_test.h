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

template<typename T, typename F = std::less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

class DebugDelete {
public:
    explicit DebugDelete(std::ostream& s = std::cerr) : os(s) {}

    template<typename T>
    void operator()(T* p) const {
        os << "Delete unique_ptr.\n";
        delete p;
    }

private:
    std::ostream& os;
};

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

template<typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template<typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
    if (data->size() <= i) {
        throw std::out_of_range(msg);
    }
}

template<typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob.");
    return data->back();
}

template<typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob.");
    return data->front();
}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob.");
    data->pop_back();
}

template<typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range.");
    return (*data)[i];
}

}// namespace TemplateTest

#endif//LEETCODE_PRACTICE_TEMPLATE_TEST_H
