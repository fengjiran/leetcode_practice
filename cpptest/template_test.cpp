//
// Created by richard on 3/25/24.
//
#include "template_test.h"
namespace TemplateTest {

TEST(TemplateTest, test2) {
    Blob<std::string> blob{"abc", "def"};
}

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

TEST(TemplateTest, test1) {
    std::cout << myMax(3, 7) << std::endl;
    std::cout << myMax(3.0, 7.0) << std::endl;
    std::cout << myMax('g', 'e') << std::endl;
}

//TEST(TemplateTest, test2) {
//    Blob<std::string> blob{"abc", "def"};
//}

}// namespace TemplateTest
