//
// Created by richard on 1/22/24.
//
#include "utils.h"

namespace HouseRobberI {
class Solution {
public:
    // use dp table
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

    // use recursive
    int rob1(std::vector<int>& nums) {
        int n = (int) nums.size();
        memo.resize(n + 1, -1);
        return dp(nums, n);
    }

    int dp(std::vector<int>& nums, int i) {
        if (i == 0) {
            return 0;
        }
        if (i == 1) {
            return nums[0];
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = std::max(dp(nums, i - 1), dp(nums, i - 2) + nums[i - 1]);
        return memo[i];
    }

    std::vector<int> memo;
};
}// namespace HouseRobberI

TEST(Solution, rob) {
    HouseRobberI::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 3, 1};
    EXPECT_EQ(sln.rob(nums1), 4);
    EXPECT_EQ(sln.rob1(nums1), 4);
    sln.memo.clear();

    // case2
    std::vector<int> nums2{2, 7, 9, 3, 1};
    EXPECT_EQ(sln.rob(nums2), 12);
    EXPECT_EQ(sln.rob1(nums2), 12);
}