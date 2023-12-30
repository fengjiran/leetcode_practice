//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace SubIslands {
class Solution {
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    res++;
                    dfs(grid2, i, j);
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
}// namespace SubIslands

TEST(Solution, countSubIslands) {
    SubIslands::Solution sln;

    // case1
    std::vector<std::vector<int>> grid_1_1 = {
            {1, 1, 1, 0, 0},
            {0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1}};
    std::vector<std::vector<int>> grid_1_2 = {
            {1, 1, 1, 0, 0},
            {0, 0, 1, 1, 1},
            {0, 1, 0, 0, 0},
            {1, 0, 1, 1, 0},
            {0, 1, 0, 1, 0}};
    EXPECT_EQ(sln.countSubIslands(grid_1_1, grid_1_2), 3);

    // case2
    std::vector<std::vector<int>> grid_2_1 = {
            {1, 0, 1, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {1, 0, 1, 0, 1}};
    std::vector<std::vector<int>> grid_2_2 = {
            {0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0},
            {1, 0, 0, 0, 1}};
    EXPECT_EQ(sln.countSubIslands(grid_2_1, grid_2_2), 2);
}