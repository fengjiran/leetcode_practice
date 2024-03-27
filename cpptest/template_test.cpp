//
// Created by richard on 3/25/24.
//
#include "template_test.h"
namespace TemplateTest {

TEST(TemplateTest, test1) {
    std::cout << "\nTemplateTest_test1:\n";
    std::cout << myMax(3, 7) << std::endl;
    std::cout << myMax(3.0, 7.0) << std::endl;
    std::cout << myMax('g', 'e') << std::endl;
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

}// namespace TemplateTest
