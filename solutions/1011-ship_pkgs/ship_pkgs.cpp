//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace ShipPkgs {
class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
    }
};
}// namespace ShipPkgs

TEST(Solution, shipPkgs) {
    ShipPkgs::Solution sln;

    // case1
    std::vector<int> weights1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(sln.shipWithinDays(weights1, 5), 15);

    // case2
    std::vector<int> weights2{3, 2, 2, 4, 1, 4};
    EXPECT_EQ(sln.shipWithinDays(weights2, 3), 6);

    // case3
    std::vector<int> weights3{1, 2, 3, 1, 1};
    EXPECT_EQ(sln.shipWithinDays(weights3, 4), 3);
}