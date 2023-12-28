//
// Created by richard on 12/28/23.
//
#include "utils.h"

namespace NumberOfIslands {
class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }

    void DFS(std::vector<std::vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }
};
}// namespace NumberOfIslands

TEST(Solution, numIslands) {
    NumberOfIslands::Solution sln;

    // case1
    std::vector<std::vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                            {'1', '1', '0', '1', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(sln.numIslands(grid1), 1);

    // case2
    std::vector<std::vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '1', '0', '0'},
                                            {'0', '0', '0', '1', '1'}};
    EXPECT_EQ(sln.numIslands(grid2), 3);
}