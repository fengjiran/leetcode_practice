//
// Created by richard on 3/25/24.
//
#include "template_test.h"
namespace TemplateTest {

extern template int myMax(const int&, const int&);
extern template double myMax(const double&, const double&);
extern template char myMax(const char&, const char&);

extern template int compare(const int&, const int&, std::less<int>);

extern template class Blob<std::string>;

TEST(TemplateTest, test1) {
    std::cout << "\nTemplateTest_test1:\n";
    std::cout << myMax(3, 7) << std::endl;
    std::cout << myMax(3.0, 7.0) << std::endl;
    std::cout << myMax('g', 'e') << std::endl;
    std::cout << compare("hello", "world") << std::endl;
}

TEST(TemplateTest, test2) {
    std::cout << "\nTemplateTest_test2:\n";
    Blob<std::string> blob{"abc", "def"};
    std::cout << "blob size: " << blob.size() << std::endl;
}

TEST(TemplateTest, test3) {
    std::cout << "\nTemplateTest_test3:\n";
    auto* p = new double;
    DebugDelete d;
    d(p);

    int* ip = new int;
    DebugDelete()(ip);
}

TEST(TemplateTest, test4) {
    std::cout << "\nTemplateTest_test4:\n";
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    print(std::cout, i, d, s, 42);
}

}// namespace TemplateTest
