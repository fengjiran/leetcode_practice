//
// Created by 赵丹 on 2024/3/30.
//
#include "template_test.h"
namespace TemplateTest {

template int myMax(const int&, const int&);
template double myMax(const double&, const double&);
template char myMax(const char&, const char&);

template int compare(const int&, const int&, std::less<int>);

template class Blob<std::string>;
}// namespace TemplateTest