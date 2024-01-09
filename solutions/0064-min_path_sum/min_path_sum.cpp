//
// Created by richard on 1/9/24.
//
#include "utils.h"

namespace MinPathSum {
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        memo.resize(m, std::vector<int>(n, -1));
        return dp(grid, m - 1, n - 1);
    }

    int dp(std::vector<std::vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[0][0];
        }
        if (i < 0 || j < 0) {
            return std::numeric_limits<int>::max();
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = std::min(dp(grid, i - 1, j), dp(grid, i, j - 1)) + grid[i][j];
        return memo[i][j];
    }

    // use dp table
    int minPathSum1(std::vector<std::vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }

    std::vector<std::vector<int>> memo;
};
}// namespace MinPathSum

TEST(Solution, minPathSum) {
    MinPathSum::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    EXPECT_EQ(sln.minPathSum(grid1), 7);
    EXPECT_EQ(sln.minPathSum1(grid1), 7);

    sln.memo.clear();

    // case2
    std::vector<std::vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(sln.minPathSum(grid2), 12);
    EXPECT_EQ(sln.minPathSum1(grid2), 12);
}