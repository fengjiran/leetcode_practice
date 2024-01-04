//
// Created by richard on 1/4/24.
//
#include "utils.h"

namespace {
class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n + 1);
        return dp(n, memo);
    }

    int dp(int n, std::vector<int>& memo) {
        if (n == 1 || n == 2) {
            memo[n] = n;
            return n;
        }

        if (memo[n] != 0) {
            return memo[n];
        }

        memo[n] = dp(n - 1, memo) + dp(n - 2, memo);
        return memo[n];
    }
};
}// namespace

TEST(Solution, climbStairs) {
    ::Solution sln;

    // case1
    EXPECT_EQ(sln.climbStairs(2), 2);

    // case2
    EXPECT_EQ(sln.climbStairs(10), 89);
}