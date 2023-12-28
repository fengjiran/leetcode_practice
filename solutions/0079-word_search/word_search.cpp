//
// Created by 赵丹 on 2023/12/24.
//
#include "utils.h"

namespace WordSearch {
class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        m = board.size();
        n = board[0].size();
        used.resize(m, std::vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtrack(board, i, j, 0, word);
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    void backtrack(std::vector<std::vector<char>>& board, int row, int col, int idx, std::string& word) {
        if (idx == word.size()) {
            found = true;
            return;
        }

        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }

        if (board[row][col] != word[idx] || used[row][col]) {
            return;
        }

        if (found) {
            return;
        }

        used[row][col] = true;
        backtrack(board, row - 1, col, idx + 1, word);
        backtrack(board, row + 1, col, idx + 1, word);
        backtrack(board, row, col - 1, idx + 1, word);
        backtrack(board, row, col + 1, idx + 1, word);
        used[row][col] = false;
    }

private:
    bool found{false};
    int m;
    int n;
    std::vector<std::vector<bool>> used;
};
}// namespace WordSearch

TEST(Solution, wordSearch) {
    WordSearch::Solution sln;
    std::vector<std::vector<char>> board1{{'A', 'B', 'C', 'E'},
                                          {'S', 'F', 'C', 'S'},
                                          {'A', 'D', 'E', 'E'}};
    std::string target1 = "ABCCED";
    EXPECT_TRUE(sln.exist(board1, target1));
}