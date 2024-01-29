//
// Created by richard on 12/28/23.
//
#include "utils.h"

namespace NumberClosedIslands {
class Solution {
public:
    int closedIslandDFS(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            DFS(grid, i, 0);
            DFS(grid, i, n - 1);
        }

        for (int j = 1; j < n - 1; j++) {
            DFS(grid, 0, j);
            DFS(grid, m - 1, j);
        }

        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }

    int closedIslandBFS(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                BFS(grid, i, 0);
            }
            if (grid[i][n - 1] == 0) {
                BFS(grid, i, n - 1);
            }
        }

        for (int j = 1; j < n - 1; j++) {
            if (grid[0][j] == 0) {
                BFS(grid, 0, j);
            }
            if (grid[m - 1][j] == 0) {
                BFS(grid, m - 1, j);
            }
        }

        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    res++;
                    BFS(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    void DFS(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            DFS(grid, i + dirs[k], j + dirs[k + 1]);
        }
    }

    void BFS(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1) {
                    continue;
                }
                grid[x][y] = 1;
                q.emplace(x, y);
            }
        }
    }

    std::vector<int> dirs{-1, 0, 1, 0, -1};
};
}// namespace NumberClosedIslands

TEST(Solution, closedIslandDFS) {
    NumberClosedIslands::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{1, 1, 1, 1, 1, 1, 1, 0},
                                           {1, 0, 0, 0, 0, 1, 1, 0},
                                           {1, 0, 1, 0, 1, 1, 1, 0},
                                           {1, 0, 0, 0, 0, 1, 0, 1},
                                           {1, 1, 1, 1, 1, 1, 1, 0}};
    auto grid11 = grid1;
    EXPECT_EQ(sln.closedIslandDFS(grid1), 2);
    EXPECT_EQ(sln.closedIslandBFS(grid11), 2);

    // case2
    std::vector<std::vector<int>> grid2 = {{0, 0, 1, 0, 0},
                                           {0, 1, 0, 1, 0},
                                           {0, 1, 1, 1, 0}};
    auto grid22 = grid2;
    EXPECT_EQ(sln.closedIslandDFS(grid2), 1);
    EXPECT_EQ(sln.closedIslandBFS(grid22), 1);

    // case3
    std::vector<std::vector<int>> grid3 = {{1, 1, 1, 1, 1, 1, 1},
                                           {1, 0, 0, 0, 0, 0, 1},
                                           {1, 0, 1, 1, 1, 0, 1},
                                           {1, 0, 1, 0, 1, 0, 1},
                                           {1, 0, 1, 1, 1, 0, 1},
                                           {1, 0, 0, 0, 0, 0, 1},
                                           {1, 1, 1, 1, 1, 1, 1}};
    auto grid33 = grid3;
    EXPECT_EQ(sln.closedIslandDFS(grid3), 2);
    EXPECT_EQ(sln.closedIslandBFS(grid33), 2);
}