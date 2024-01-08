//
// Created by richard on 1/8/24.
//
#include "utils.h"

namespace LongestPalindromicSubseq {
class Solution {
public:
    int longestPalindromeSubseq(std::string& s) {
        int m = static_cast<int>(s.length());
        memo.resize(m, std::vector<int>(m, -1));
        return dp(s, 0, m - 1);
    }

    int dp(const std::string& s, int i, int j) {
        if (i > j) {
            memo[i][j] = 0;
            return memo[i][j];
        }

        if (i == j) {
            memo[i][j] = 1;
            return memo[i][j];
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s[i] == s[j]) {
            memo[i][j] = dp(s, i + 1, j - 1) + 2;
        } else {
            memo[i][j] = std::max(dp(s, i + 1, j), dp(s, i, j - 1));
        }
        return memo[i][j];
    }

    std::vector<std::vector<int>> memo;
};
}// namespace LongestPalindromicSubseq

TEST(Solution, longestPalindromeSubseq) {
    LongestPalindromicSubseq::Solution sln;

    // case1
    std::string s1 = "bbbab";
    EXPECT_EQ(sln.longestPalindromeSubseq(s1), 4);
    sln.memo.clear();

    // case2
    std::string s2 = "cbbd";
    EXPECT_EQ(sln.longestPalindromeSubseq(s2), 2);
}