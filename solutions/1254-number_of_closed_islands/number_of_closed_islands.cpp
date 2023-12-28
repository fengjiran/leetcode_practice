//
// Created by richard on 12/28/23.
//
#include "utils.h"

namespace NumberClosedIslands {
class Solution {
public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            DFS(grid, i, 0);
            DFS(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            DFS(grid, 0, j);
            DFS(grid, m - 1, j);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }

    void DFS(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1;
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }
};
}// namespace NumberClosedIslands

TEST(Solution, closedIsland) {
    NumberClosedIslands::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{1, 1, 1, 1, 1, 1, 1, 0},
                                           {1, 0, 0, 0, 0, 1, 1, 0},
                                           {1, 0, 1, 0, 1, 1, 1, 0},
                                           {1, 0, 0, 0, 0, 1, 0, 1},
                                           {1, 1, 1, 1, 1, 1, 1, 0}};
    EXPECT_EQ(sln.closedIsland(grid1), 2);

    // case2
    std::vector<std::vector<int>> grid2 = {{0, 0, 1, 0, 0},
                                           {0, 1, 0, 1, 0},
                                           {0, 1, 1, 1, 0}};
    EXPECT_EQ(sln.closedIsland(grid2), 1);

    // case3
    std::vector<std::vector<int>> grid3 = {{1, 1, 1, 1, 1, 1, 1},
                                           {1, 0, 0, 0, 0, 0, 1},
                                           {1, 0, 1, 1, 1, 0, 1},
                                           {1, 0, 1, 0, 1, 0, 1},
                                           {1, 0, 1, 1, 1, 0, 1},
                                           {1, 0, 0, 0, 0, 0, 1},
                                           {1, 1, 1, 1, 1, 1, 1}};
    EXPECT_EQ(sln.closedIsland(grid3), 2);
}