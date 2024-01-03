//
// Created by richard on 1/4/24.
//
#include "utils.h"

namespace MinFallPath {
class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        memo.resize(n, std::vector<int>(n, 66666));
        int res = INT32_MAX;
        for (int j = 0; j < n; j++) {
            res = std::min(res, dp(matrix, n - 1, j));
        }
        return res;
    }

    int dp(std::vector<std::vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        if (i < 0 || j < 0 || i >= n || j >= n) {
            return 66666;
        }
        if (i == 0) {
            return matrix[i][j];
        }

        if (memo[i][j] != 66666) {
            return memo[i][j];
        }

        memo[i][j] = matrix[i][j] + std::min({dp(matrix, i - 1, j),
                                              dp(matrix, i - 1, j - 1),
                                              dp(matrix, i - 1, j + 1)});
        return memo[i][j];
    }

    std::vector<std::vector<int>> memo;
};
}// namespace MinFallPath

TEST(Solution, minFallingPathSum) {
    MinFallPath::Solution sln;

    // case1
    std::vector<std::vector<int>> matrix1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    EXPECT_EQ(sln.minFallingPathSum(matrix1), 13);
}