//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace Triangle {
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = (int) triangle.size();
        std::vector<std::vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(triangle[i].size());
        }
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }

        int res = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            res = std::min(dp[n - 1][i], res);
        }
        return res;
    }
};
}// namespace Triangle

TEST(Solution, minimumTotal) {
    Triangle::Solution sln;

    // case1
    std::vector<std::vector<int>> triangle1{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    EXPECT_EQ(sln.minimumTotal(triangle1), 11);
}