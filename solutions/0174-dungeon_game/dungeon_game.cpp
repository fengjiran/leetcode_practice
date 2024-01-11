//
// Created by 赵丹 on 2024/1/11.
//
#include "utils.h"

namespace DungeonGame {
class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = static_cast<int>(dungeon.size());
        int n = static_cast<int>(dungeon[0].size());
        memo.resize(m, std::vector<int>(n, -1));
        return dp(dungeon, 0, 0);
    }

    int dp(const std::vector<std::vector<int>>& grid, int i, int j) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        if (i == m - 1 && j == n - 1) {
            memo[i][j] = grid[i][j] >= 0 ? 1 : -grid[i][j] + 1;
            return memo[i][j];
        }

        if (i == m || j == n) {
            return std::numeric_limits<int>::max();
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = std::min(dp(grid, i + 1, j), dp(grid, i, j + 1)) - grid[i][j];
        memo[i][j] = memo[i][j] > 0 ? memo[i][j] : 1;
        return memo[i][j];
    }

    std::vector<std::vector<int>> memo;
};
}// namespace DungeonGame

TEST(Solution, calculateMinimumHP) {
    DungeonGame::Solution sln;

    // case1
    std::vector<std::vector<int>> dungeon1{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    EXPECT_EQ(sln.calculateMinimumHP(dungeon1), 7);

    sln.memo.clear();

    // case2
    std::vector<std::vector<int>> dungeon2{{0}};
    EXPECT_EQ(sln.calculateMinimumHP(dungeon2), 1);
}