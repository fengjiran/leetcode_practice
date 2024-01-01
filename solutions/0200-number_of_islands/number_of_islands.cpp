//
// Created by richard on 12/28/23.
//
#include "utils.h"

namespace NumberOfIslands {
class Solution {
public:
    int numIslandsDFS(std::vector<std::vector<char>>& grid) {
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

    int numIslandsBFS(std::vector<std::vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    BFS(grid, i, j);
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

    void BFS(std::vector<std::vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            int sz = q.size();
            for (int p = 0; p < sz; p++) {
                std::pair<int, int> cur = q.front();
                q.pop();
                if (cur.first < 0 || cur.first >= m || cur.second < 0 || cur.second >= n) {
                    continue;
                }
                if (grid[cur.first][cur.second] == '0') {
                    continue;
                }

                grid[cur.first][cur.second] = '0';
                q.emplace(cur.first, cur.second - 1);
                q.emplace(cur.first, cur.second + 1);
                q.emplace(cur.first - 1, cur.second);
                q.emplace(cur.first + 1, cur.second);
            }
        }
    }
};
}// namespace NumberOfIslands

TEST(Solution, numIslandsDFS) {
    NumberOfIslands::Solution sln;

    // case1
    std::vector<std::vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                            {'1', '1', '0', '1', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(sln.numIslandsDFS(grid1), 1);

    // case2
    std::vector<std::vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '1', '0', '0'},
                                            {'0', '0', '0', '1', '1'}};
    EXPECT_EQ(sln.numIslandsDFS(grid2), 3);
}

TEST(Solution, numIslandsBFS) {
    NumberOfIslands::Solution sln;

    // case1
    std::vector<std::vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                            {'1', '1', '0', '1', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(sln.numIslandsBFS(grid1), 1);

    // case2
    std::vector<std::vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                            {'1', '1', '0', '0', '0'},
                                            {'0', '0', '1', '0', '0'},
                                            {'0', '0', '0', '1', '1'}};
    EXPECT_EQ(sln.numIslandsBFS(grid2), 3);
}