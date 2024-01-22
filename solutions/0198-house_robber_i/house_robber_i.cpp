//
// Created by richard on 1/22/24.
//
#include "utils.h"

namespace HouseRobberI {
class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = (int) nums.size();
        std::vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
}// namespace HouseRobberI

TEST(Solution, rob) {
    HouseRobberI::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 3, 1};
    EXPECT_EQ(sln.rob(nums1), 4);

    // case2
    std::vector<int> nums2{2, 7, 9, 3, 1};
    EXPECT_EQ(sln.rob(nums2), 12);
}