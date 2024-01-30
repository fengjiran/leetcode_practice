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
        for (int k = 0; k < 4; k++) {
            DFS(grid, i + dirs[k], j + dirs[k + 1]);
        }
    }

    void BFS(std::vector<std::vector<char>>& grid, int i, int j) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == '0') {
                continue;
            }

            grid[a][b] = '0';
            for (int p = 0; p < 4; p++) {
                q.emplace(a + dirs[p], b + dirs[p + 1]);
            }
        }
    }

    void BFS1(std::vector<std::vector<char>>& grid, int i, int j) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = a + dirs[k];
                int y = b + dirs[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
                    continue;
                }
                grid[x][y] = '0';
                q.emplace(x, y);
            }
        }
    }

private:
    std::vector<int> dirs{-1, 0, 1, 0, -1};
};
}// namespace NumberOfIslands

TEST(Solution, numIslands) {
    std::optional<std::string> dir = getFileDir(__FILE__);
    EXPECT_TRUE(dir.has_value());

    std::string case1Path = dir.value() + "/" + "grid1.txt";
    std::string case2Path = dir.value() + "/" + "grid2.txt";
    std::optional<std::vector<std::vector<char>>> grid1 = get2DCharFromFile(case1Path.c_str());
    std::optional<std::vector<std::vector<char>>> grid2 = get2DCharFromFile(case2Path.c_str());
    EXPECT_TRUE(grid1.has_value());
    EXPECT_TRUE(grid2.has_value());

    NumberOfIslands::Solution sln;

    // case1
    auto grid11 = grid1;
    EXPECT_EQ(sln.numIslandsBFS(grid1.value()), 1);
    EXPECT_EQ(sln.numIslandsDFS(grid11.value()), 1);

    // case2
    auto grid21 = grid2;
    EXPECT_EQ(sln.numIslandsBFS(grid2.value()), 3);
    EXPECT_EQ(sln.numIslandsDFS(grid21.value()), 3);
}