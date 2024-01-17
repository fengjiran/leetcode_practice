//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace Sqrtx {
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x <= 3) {
            return 1;
        }

        int left = 1;
        int right = x / 2 + 1;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long tmp = mid * mid;
            long tmp2 = (mid + 1) * (mid + 1);
            if (tmp <= x && tmp2 > x) {
                return mid;
            } else if (tmp > x) {
                right = mid - 1;
            } else if (tmp < x) {
                left = mid + 1;
            }
        }
        return 0;
    }
};
}// namespace Sqrtx

TEST(Solution, mySqrt) {
    Sqrtx::Solution sln;

    // case1
    EXPECT_EQ(sln.mySqrt(4), 2);

    // case2
    EXPECT_EQ(sln.mySqrt(8), 2);
}