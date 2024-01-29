//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace MaxAreaIsland {
class Solution {
public:
    int maxAreaOfIslandDFS(std::vector<std::vector<int>>& grid) {
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

    int maxAreaOfIslandBFS(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = std::max(res, bfs(grid, i, j));
                }
            }
        }
        return res;
    }

private:
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
        int res = 1;
        for (int k = 0; k < 4; k++) {
            res += dfs(grid, i + dirs[k], j + dirs[k + 1]);
        }
        return res;
    }

    int bfs(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = (int) grid.size();
        int n = (int) grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        grid[i][j] = 0;
        int res = 1;
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                    continue;
                }
                grid[x][y] = 0;
                res++;
                q.emplace(x, y);
            }
        }
        return res;
    }

    std::vector<int> dirs{-1, 0, 1, 0, -1};
};
}// namespace MaxAreaIsland

TEST(Solution, maxAreaOfIslandDFS) {
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
    auto grid11 = grid1;
    EXPECT_EQ(sln.maxAreaOfIslandDFS(grid1), 6);
    EXPECT_EQ(sln.maxAreaOfIslandBFS(grid11), 6);

    // case2
    std::vector<std::vector<int>> grid2 = {{0, 0, 0, 0, 0, 0, 0, 0}};
    auto grid22 = grid2;
    EXPECT_EQ(sln.maxAreaOfIslandDFS(grid2), 0);
    EXPECT_EQ(sln.maxAreaOfIslandBFS(grid22), 0);
}