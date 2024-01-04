//
// Created by richard on 1/4/24.
//
#include "utils.h"

namespace LongestIncreaseSubseq {
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int it: dp) {
            if (it > res) {
                res = it;
            }
        }
        return res;
    }

    int lengthOfLIS1(std::vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = std::max(res, dp(nums, i));
        }
        return res;
    }

    int dp(std::vector<int>& nums, int i) {
        if (i == 0) {
            return 1;
        }

        if (memo[i] != 1) {
            return memo[i];
        }

        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                memo[i] = std::max(memo[i], dp(nums, j) + 1);
            }
        }
        return memo[i];
    }

    void resetMems() {
        memo.clear();
    }

    std::vector<int> memo;
};
}// namespace LongestIncreaseSubseq

TEST(Solution, lengthOfLIS) {
    LongestIncreaseSubseq::Solution sln;

    // case1
    std::vector<int> nums1{10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(sln.lengthOfLIS(nums1), 4);
    EXPECT_EQ(sln.lengthOfLIS1(nums1), 4);
    sln.resetMems();

    // case2
    std::vector<int> nums2{0, 1, 0, 3, 2, 3};
    EXPECT_EQ(sln.lengthOfLIS(nums2), 4);
    EXPECT_EQ(sln.lengthOfLIS1(nums2), 4);
    sln.resetMems();

    // case3
    std::vector<int> nums3{7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(sln.lengthOfLIS(nums3), 1);
    EXPECT_EQ(sln.lengthOfLIS1(nums3), 1);
}
