//
// Created by 赵丹 on 2024/1/7.
//
#include "utils.h"

namespace LCS {
class Solution {
public:
    // use iteration
    int longestCommonSubsequence(std::string& text1, std::string& text2) {
        size_t m = text1.length();
        size_t n = text2.length();
        memo.resize(m, std::vector<int>(n, -1));
        return dp(text1, 0, text2, 0);
    }

    // use dp table
    int LCS(std::string& text1, std::string& text2) {
        size_t m = text1.length();
        size_t n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int dp(std::string& s1, int i, std::string& s2, int j) {
        if (i == s1.length() || j == s2.length()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, i + 1, s2, j + 1) + 1;
        } else {
            memo[i][j] = std::max(
                    dp(s1, i + 1, s2, j),
                    dp(s1, i, s2, j + 1));
        }
        return memo[i][j];
    }

    std::vector<std::vector<int>> memo;
};
}// namespace LCS

TEST(Solution, longestCommonSubsequence) {
    LCS::Solution sln;

    // case1
    std::string text1 = "abcde";
    std::string text2 = "ace";
    EXPECT_EQ(sln.longestCommonSubsequence(text1, text2), 3);
    EXPECT_EQ(sln.LCS(text1, text2), 3);
}