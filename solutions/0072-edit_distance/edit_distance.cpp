//
// Created by 赵丹 on 2024/1/6.
//
#include "utils.h"

namespace EditDistance {
class Solution {
public:
    // use recursion
    int minDistance(std::string& word1, std::string& word2) {
        int m = (int) word1.size();
        int n = (int) word2.size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
        return dp(word1, m - 1, word2, n - 1, memo);
    }

    // use iteration(dp table)
    int minDistance1(std::string& word1, std::string& word2) {
        size_t m = word1.length();
        size_t n = word2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j] + 1,
                                         dp[i][j - 1] + 1,
                                         dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[m][n];
    }

    // space compression
    int minDistance2(std::string& word1, std::string& word2) {
        size_t m = word1.length();
        size_t n = word2.length();
        std::vector<int> dp(n + 1);
        for (int j = 1; j <= n; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            int tmp1 = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int tmp2 = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = tmp1;
                } else {
                    dp[j] = std::min({tmp2 + 1, dp[j - 1] + 1, tmp1 + 1});
                }
                tmp1 = tmp2;
            }
        }
        return dp[n];
    }

    int dp(std::string& s1, int i, std::string& s2, int j, std::vector<std::vector<int>>& memo) {
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, i - 1, s2, j - 1, memo);
        } else {
            memo[i][j] = std::min({dp(s1, i, s2, j - 1, memo) + 1,
                                   dp(s1, i - 1, s2, j, memo) + 1,
                                   dp(s1, i - 1, s2, j - 1, memo) + 1});
        }

        return memo[i][j];
    }
};
}// namespace EditDistance

TEST(Solution, minDistance) {
    EditDistance::Solution sln;

    // case1
    std::string word1 = "horse";
    std::string word2 = "ros";
    EXPECT_EQ(sln.minDistance(word1, word2), 3);
    EXPECT_EQ(sln.minDistance1(word1, word2), 3);
    EXPECT_EQ(sln.minDistance2(word1, word2), 3);
    // case2
}