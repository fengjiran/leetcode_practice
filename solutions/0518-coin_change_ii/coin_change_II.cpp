//
// Created by richard on 1/9/24.
//
#include "utils.h"

namespace CoinChangeII {
class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }
        return dp[n][amount];
    }

    // use space compression skill
    int change1(int amount, std::vector<int>& coins) {
        int n = coins.size();
        std::vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i-1]){
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                }
            }
        }
        return dp[amount];
    }
};
}// namespace CoinChangeII

TEST(Solution, change) {
    CoinChangeII::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 5};
    EXPECT_EQ(sln.change(5, nums1), 4);
    EXPECT_EQ(sln.change1(5, nums1), 4);

    // case2
    std::vector<int> nums2{2};
    EXPECT_EQ(sln.change(3, nums2), 0);
    EXPECT_EQ(sln.change1(3, nums2), 0);

    // case3
    std::vector<int> nums3{10};
    EXPECT_EQ(sln.change(10, nums3), 1);
    EXPECT_EQ(sln.change1(10, nums3), 1);
}