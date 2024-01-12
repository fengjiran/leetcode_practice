//
// Created by richard on 1/12/24.
//
#include "utils.h"

namespace LeavingString {
class Solution {
public:
    bool isInterleave(const std::string& s1, const std::string& s2, const std::string& s3) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());
        int k = static_cast<int>(s3.size());
        if (m + n != k) {
            return false;
        }

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int t = i + j - 1;
                if (i > 0) {
                    dp[i][j] = dp[i][j] || (s1[i - 1] == s3[t] && dp[i - 1][j]);
                }

                if (j > 0) {
                    dp[i][j] = dp[i][j] || (s2[j - 1] == s3[t] && dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    bool isInterleaveWithSpaceCompression(const std::string& s1, const std::string& s2, const std::string& s3) {
        int m = static_cast<int>(s1.size());
        int n = static_cast<int>(s2.size());
        int k = static_cast<int>(s3.size());
        if (m + n != k) {
            return false;
        }

        std::vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int t = i + j - 1;
                if (i > 0) {
                    dp[j] = dp[j] && s1[i - 1] == s3[t];
                }
                if (j > 0) {
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[t]);
                }
            }
        }
        return dp[n];
    }
};
}// namespace LeavingString

TEST(Solution, isInterleave) {
    LeavingString::Solution sln;

    // case1
    EXPECT_TRUE(sln.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_TRUE(sln.isInterleaveWithSpaceCompression("aabcc", "dbbca", "aadbbcbcac"));

    // case2
    EXPECT_FALSE(sln.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    EXPECT_FALSE(sln.isInterleaveWithSpaceCompression("aabcc", "dbbca", "aadbbbaccc"));

    // case3
    EXPECT_TRUE(sln.isInterleave("", "", ""));
    EXPECT_TRUE(sln.isInterleaveWithSpaceCompression("", "", ""));
}