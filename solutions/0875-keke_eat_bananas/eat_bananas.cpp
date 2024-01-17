//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace EatBananas {
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getTimes(piles, mid) > h) {
                left = mid + 1;
            } else if (getTimes(piles, mid) < h) {
                right = mid;
            } else if (getTimes(piles, mid) == h) {
                right = mid;
            }
        }

        return left;
    }

    long getTimes(std::vector<int>& piles, int x) {
        long hours = 0;
        for (int pile: piles) {
            hours += pile / x;
            if (pile % x > 0) {
                hours++;
            }
        }
        return hours;
    }
};
}// namespace EatBananas

TEST(Solution, kekeEatBanana) {
    EatBananas::Solution sln;

    // case1
    std::vector<int> piles1{3, 6, 7, 11};
    EXPECT_EQ(sln.minEatingSpeed(piles1, 8), 4);

    // case2
    std::vector<int> piles2{30, 11, 23, 4, 20};
    EXPECT_EQ(sln.minEatingSpeed(piles2, 5), 30);

    // case3
    EXPECT_EQ(sln.minEatingSpeed(piles2, 6), 23);
}