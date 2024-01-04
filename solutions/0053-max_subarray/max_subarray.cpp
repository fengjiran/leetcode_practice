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


    // use pre sum

    // use slide window
};
}// namespace MaxSubarray

TEST(Solution, maxSubArray) {
    MaxSubarray::Solution sln;

    // case1
    std::vector<int> nums1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(sln.maxSubArray(nums1), 6);

    // case2
    std::vector<int> nums2{1};
    EXPECT_EQ(sln.maxSubArray(nums2), 1);

    // case3
    std::vector<int> nums3{5, 4, -1, 7, 8};
    EXPECT_EQ(sln.maxSubArray(nums3), 23);
}