//
// Created by richard on 1/4/24.
//
#include "utils.h"

namespace MaxSubarray {
class Solution {
public:
    // use DP
    int maxSubArray(std::vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
        }

        int res = INT32_MIN;
        for (int i = 0; i < n; i++) {
            res = std::max(res, dp[i]);
        }

        return res;
    }

    int maxSubArray1(std::vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> memo(n, INT32_MAX);
        int res = INT32_MIN;
        for (int i = 0; i < n; i++) {
            res = std::max(res, dp(nums, i, memo));
        }
        return res;
    }

    int dp(std::vector<int>& nums, int i, std::vector<int>& memo) {
        if (i == 0) {
            memo[i] = nums[i];
            return memo[i];
        }

        if (memo[i] != INT32_MAX) {
            return memo[i];
        }

        memo[i] = std::max(nums[i], dp(nums, i - 1, memo) + nums[i]);

        return memo[i];
    }


    // use pre sum

    // use slide window
};
}// namespace MaxSubarray

TEST(Solution, maxSubArray) {
    MaxSubarray::Solution sln;

    // case1
    std::vector<int> nums1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(sln.maxSubArray(nums1), 6);
    EXPECT_EQ(sln.maxSubArray1(nums1), 6);

    // case2
    std::vector<int> nums2{1};
    EXPECT_EQ(sln.maxSubArray(nums2), 1);
    EXPECT_EQ(sln.maxSubArray1(nums2), 1);

    // case3
    std::vector<int> nums3{5, 4, -1, 7, 8};
    EXPECT_EQ(sln.maxSubArray(nums3), 23);
    EXPECT_EQ(sln.maxSubArray1(nums3), 23);
}