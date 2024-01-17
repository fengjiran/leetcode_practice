//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace ShipPkgs {
class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for (int weight: weights) {
            left = std::max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getDays(weights, mid) > days) {
                left = mid + 1;
            } else if (getDays(weights, mid) < days) {
                right = mid;
            } else if (getDays(weights, mid) == days) {
                right = mid;
            }
        }
        return left;
    }

    int getDays(std::vector<int>& weights, int cap) {
        int days = 0;
        int sum = 0;
        int i = 0;
        while (i < weights.size()) {
            sum += weights[i];
            if (sum > cap) {
                days++;
                sum = 0;
                continue;
            }
            if (i == weights.size() - 1) {
                days++;
            }
            i++;
        }
        return days;
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