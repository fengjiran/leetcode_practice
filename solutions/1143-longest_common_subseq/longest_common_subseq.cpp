//
// Created by 赵丹 on 2024/1/7.
//
#include "utils.h"

namespace LCS {
class Solution {
public:
    int longestCommonSubsequence(std::string& text1, std::string& text2) {
        size_t m = text1.length();
        size_t n = text2.length();
        memo.resize(m, std::vector<int>(n, -1));
        return dp(text1, 0, text2, 0);
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
}