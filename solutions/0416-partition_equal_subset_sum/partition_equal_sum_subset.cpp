//
// Created by 赵丹 on 2024/1/10.
//
#include "utils.h"

namespace EqualSumSubsetPartition {
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (int val: nums) {
            sum += val;
        }

        if (sum % 2 == 1) {
            return false;
        }

        int m = sum / 2;

        int n = static_cast<int>(nums.size());
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][m];
    }

    bool canPartition1(std::vector<int>& nums) {
        int sum = 0;
        for (int val: nums) {
            sum += val;
        }

        if (sum % 2 == 1) {
            return false;
        }

        int m = sum / 2;

        int n = static_cast<int>(nums.size());
        std::vector<bool> dp(m + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 0; j--) {
                if (j >= nums[i - 1]) {
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                }
            }
        }
        return dp[m];
    }
};
}// namespace EqualSumSubsetPartition

TEST(Solution, canPartition) {
    EqualSumSubsetPartition::Solution sln;

    // case1
    std::vector<int> nums1{1, 5, 11, 5};
    EXPECT_TRUE(sln.canPartition(nums1));
    EXPECT_TRUE(sln.canPartition1(nums1));
    // case2
    std::vector<int> nums2{1, 2, 3, 5};
    EXPECT_FALSE(sln.canPartition(nums2));
    EXPECT_FALSE(sln.canPartition1(nums2));
}