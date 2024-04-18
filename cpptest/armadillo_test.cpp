//
// Created by richard on 4/17/24.
//

#include "armadillo_test.h"

namespace ArmadilloTest {

TEST(ArmadilloTest, test1) {
    LOG(INFO) << "ArmadilloTest test1:";
//    std::cout << "\nArmadilloTest test1:\n";
    arma::mat A(4, 5, arma::fill::randu);
    arma::mat B(4, 5, arma::fill::randu);
    std::cout << A * B.t() << std::endl;
}

TEST(ArmadilloTest, test2) {
    std::cout << "\nArmadilloTest add:\n";
    arma::fmat mat1 = "1,2,3;"
                      "4,5,6;"
                      "7,8,9";
    arma::fmat mat2 = "1,2,3;"
                      "4,5,6;"
                      "7,8,9";

    arma::fmat mat3 = "2,4,6;"
                      "8,10,12;"
                      "14,16,18";

    //    ASSERT_EQ(arma::approx_equal(mat3, mat1 + mat2, "absdiff", 1e-5), true);
    EXPECT_TRUE(arma::approx_equal(mat3, mat1 + mat2, "absdiff", 1e-5));
}

TEST(ArmadilloTest, test3) {
    std::cout << "\nArmadilloTest sub:\n";
    arma::fmat mat1 = "1,2,3;"
                      "4,5,6;"
                      "7,8,9";
    arma::fmat mat2 = "1,2,3;"
                      "4,5,6;"
                      "7,8,9";

    arma::fmat mat3 = "0,0,0;"
                      "0,0,0;"
                      "0,0,0";
    EXPECT_TRUE(arma::approx_equal(mat3, mat1 - mat2, "absdiff", 1e-5));
}
}// namespace ArmadilloTest