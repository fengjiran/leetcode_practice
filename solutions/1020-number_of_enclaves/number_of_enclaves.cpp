//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace NumberOfEnclaves {
class Solution {
public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};
}// namespace NumberOfEnclaves

TEST(Solution, numEnclaves) {
    NumberOfEnclaves::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{0, 0, 0, 0},
                                           {1, 0, 1, 0},
                                           {0, 1, 1, 0},
                                           {0, 0, 0, 0}};
    EXPECT_EQ(sln.numEnclaves(grid1), 3);

    // case2
    std::vector<std::vector<int>> grid2 = {{0, 1, 1, 0},
                                           {0, 0, 1, 0},
                                           {0, 0, 1, 0},
                                           {0, 0, 0, 0}};
    EXPECT_EQ(sln.numEnclaves(grid2), 0);
}