//
// Created by richard on 1/22/24.
//
#include "utils.h"

namespace MinCostClimbStairs {
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = (int) cost.size();
        memo.resize(n + 1, -1);
        return dp(cost, n);
    }

    int minCostClimbingStairs1(std::vector<int>& cost) {
        int n = (int) cost.size();
        std::vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    // with space compression
    int minCostClimbingStairs2(std::vector<int>& cost) {
        int n = (int) cost.size();
        int tmp1 = 0;
        int tmp2 = 0;
        int tmp3;
        for (int i = 2; i <= n; i++) {
            tmp3 = std::min(tmp1 + cost[i - 1], tmp2 + cost[i - 2]);
            tmp2 = tmp1;
            tmp1 = tmp3;
        }
        return tmp1;
    }

    int dp(std::vector<int>& cost, int i) {
        if (i == 0 || i == 1) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        memo[i] = std::min(dp(cost, i - 1) + cost[i - 1], dp(cost, i - 2) + cost[i - 2]);
        return memo[i];
    }

    std::vector<int> memo;
};
}// namespace MinCostClimbStairs

TEST(Solution, minCostClimbingStairs) {
    MinCostClimbStairs::Solution sln;

    // case1
    std::vector<int> cost1{10, 15, 20};
    EXPECT_EQ(sln.minCostClimbingStairs(cost1), 15);
    EXPECT_EQ(sln.minCostClimbingStairs1(cost1), 15);
    EXPECT_EQ(sln.minCostClimbingStairs2(cost1), 15);
    sln.memo.clear();

    // case2
    std::vector<int> cost2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(sln.minCostClimbingStairs(cost2), 6);
    EXPECT_EQ(sln.minCostClimbingStairs1(cost2), 6);
    EXPECT_EQ(sln.minCostClimbingStairs2(cost2), 6);
}