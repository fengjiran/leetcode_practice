//
// Created by 赵丹 on 2024/1/2.
//
#include "utils.h"

namespace SurroundedRegions {
class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            BFS(board, i, 0);
            BFS(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            BFS(board, 0, j);
            BFS(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void BFS(std::vector<std::vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
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
                if (board[cur.first][cur.second] != 'O') {
                    continue;
                }

                board[cur.first][cur.second] = 'A';
                q.emplace(cur.first, cur.second - 1);
                q.emplace(cur.first, cur.second + 1);
                q.emplace(cur.first - 1, cur.second);
                q.emplace(cur.first + 1, cur.second);
            }
        }
    }
};
}// namespace SurroundedRegions

TEST(Solution, surroundedRegions) {
    std::optional<std::string> dir = getFileDir(__FILE__);
    EXPECT_TRUE(dir.has_value());

    std::string case1Path = dir.value() + "/" + "board1.txt";
    std::optional<std::vector<std::vector<char>>> board1 = get2DCharFromFile(case1Path.c_str());
    EXPECT_TRUE(board1.has_value());

    SurroundedRegions::Solution sln;
}