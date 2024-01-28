//
// Created by richard on 1/28/24.
//
#include "utils.h"

namespace MaxLCSNum {
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int m = (int) nums.size();
        std::vector<int> dp(m, 1);
        std::vector<int> cnt(m, 1);
        int maxLen = 0;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                res = cnt[i];
            } else if (dp[i] == maxLen) {
                res += cnt[i];
            }
        }
        return res;
    }
};
}// namespace MaxLCSNum

TEST(Solution, findNumberOfLIS) {
    MaxLCSNum::Solution sln;

    // case1
    std::vector<int> nums1{1, 3, 5, 4, 7};
    EXPECT_EQ(sln.findNumberOfLIS(nums1), 2);

    // case2
    std::vector<int> nums2{2, 2, 2, 2, 2};
    EXPECT_EQ(sln.findNumberOfLIS(nums2), 5);
}