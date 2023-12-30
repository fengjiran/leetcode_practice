//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace MaxAreaIsland {
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = std::max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;
        return dfs(grid, i, j - 1) +
               dfs(grid, i, j + 1) +
               dfs(grid, i - 1, j) +
               dfs(grid, i + 1, j) + 1;
    }
};
}// namespace MaxAreaIsland

TEST(Solution, maxAreaOfIsland) {
    MaxAreaIsland::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    EXPECT_EQ(sln.maxAreaOfIsland(grid1), 6);

    // case2
    std::vector<std::vector<int>> grid2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    EXPECT_EQ(sln.maxAreaOfIsland(grid2), 0);
}