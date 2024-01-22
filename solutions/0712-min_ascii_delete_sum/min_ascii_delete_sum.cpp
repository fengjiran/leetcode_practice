//
// Created by richard on 1/22/24.
//
#include "utils.h"

namespace MinASCIIDeleteSum {
class Solution {
public:
    int minimumDeleteSum(const std::string& s1, const std::string& s2) {
        size_t m = s1.size();
        size_t n = s2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    // with space compression
    int minimumDeleteSum1(const std::string& s1, const std::string& s2) {
        size_t m = s1.size();
        size_t n = s2.size();
        std::vector<int> dp(n + 1);
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            int tmp1 = dp[0];
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    dp[j] += s1[i - 1];
                } else {
                    int tmp2 = dp[j];
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[j] = tmp1;
                    } else {
                        dp[j] = std::min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                    }
                    tmp1 = tmp2;
                }
            }
        }
        return dp[n];
    }
};
}// namespace MinASCIIDeleteSum

TEST(Solution, minimumDeleteSum) {
    MinASCIIDeleteSum::Solution sln;

    // case1
    EXPECT_EQ(sln.minimumDeleteSum("sea", "eat"), 231);
    EXPECT_EQ(sln.minimumDeleteSum1("sea", "eat"), 231);

    // case2
    EXPECT_EQ(sln.minimumDeleteSum("delete", "leet"), 403);
    EXPECT_EQ(sln.minimumDeleteSum1("delete", "leet"), 403);
}