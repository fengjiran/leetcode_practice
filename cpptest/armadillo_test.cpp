//
// Created by richard on 4/17/24.
//

#include "armadillo_test.h"

namespace ArmadilloTest {

TEST(ArmadilloTest, test1) {
    std::cout << "\nArmadilloTest test1:\n";
    arma::mat A(4, 5, arma::fill::randu);
    arma::mat B(4, 5, arma::fill::randu);
    std::cout << A * B.t() << std::endl;
}
}// namespace ArmadilloTest