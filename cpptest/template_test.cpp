//
// Created by richard on 3/25/24.
//
#include "template_test.h"
namespace TemplateTest {

TEST(TemplateTest, test1) {
    std::cout << myMax(3, 7) << std::endl;
    std::cout << myMax(3.0, 7.0) << std::endl;
    std::cout << myMax('g', 'e') << std::endl;
}

TEST(TemplateTest, test2) {
    Blob<std::string> blob{"abc", "def"};
}

}// namespace TemplateTest
