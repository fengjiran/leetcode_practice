//
// Created by 赵丹 on 2024/1/24.
//
#include "utils.h"

namespace HouseRobberII {
class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) {
            return nums[0];
        }
        std::vector<int> dp(n);

        // range [0, n - 2]
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n - 1; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int a = dp[n - 1];
//        dp.clear();

        // range [1, n - 1]
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i <= n - 1; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return std::max(a, dp[n - 1]);
    }
};
}// namespace HouseRobberII

TEST(Solution, rob2) {
    HouseRobberII::Solution sln;

    // case1
    std::vector<int> nums1{2, 3, 2};
    EXPECT_EQ(sln.rob(nums1), 3);

    // case2
    std::vector<int> nums2{1, 2, 3, 1};
    EXPECT_EQ(sln.rob(nums2), 4);

    // case3
    std::vector<int> nums3{1, 2, 3};
    EXPECT_EQ(sln.rob(nums3), 3);
}