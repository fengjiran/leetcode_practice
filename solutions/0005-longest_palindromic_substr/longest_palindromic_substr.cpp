//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace LongestPalindromicSubstr {
class Solution {
public:
    // 中心扩散法
    std::string longestPalindrome(std::string& s) {
        int n = (int) s.size();
        int maxLen = 1;
        int begin = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            int left = i / 2;
            int right = left + i % 2;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            if (right - left - 1 > maxLen) {
                maxLen = right - left - 1;
                begin = left + 1;
            }
        }

        return s.substr(begin, maxLen);
    }

    // 动态规划
    std::string longestPalindrome1(std::string& s) {
        int n = (int) s.size();
        int maxLen = 1;
        int begin = 0;
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (i == j + 1) {
                    dp[j][i] = s[i] == s[j];
                } else {
                    dp[j][i] = dp[j + 1][i - 1] && s[i] == s[j];
                }

                if (dp[j][i] && i - j + 1 > maxLen) {
                    maxLen = i - j + 1;
                    begin = j;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
}// namespace LongestPalindromicSubstr

TEST(Solution, longestPalindrome) {
    LongestPalindromicSubstr::Solution sln;

    // case1
    std::string s1 = "babad";
    EXPECT_EQ(sln.longestPalindrome(s1), "bab");
    EXPECT_EQ(sln.longestPalindrome1(s1), "bab");

    // case2
    std::string s2 = "cbbd";
    EXPECT_EQ(sln.longestPalindrome(s2), "bb");
    EXPECT_EQ(sln.longestPalindrome1(s2), "bb");
}