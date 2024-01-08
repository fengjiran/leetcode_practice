//
// Created by 赵丹 on 2024/1/9.
//
#include "utils.h"

namespace RegexMatch {
class Solution {
public:
    bool isMatch(std::string& s, std::string& p) {
        int m = static_cast<int>(s.length());
        int n = static_cast<int>(p.length());
        memo.resize(m, std::vector<int>(n, -1));
        return dp(s, 0, p, 0);
    }

    bool dp(const std::string& s, int i, const std::string& p, int j) {
        int m = static_cast<int>(s.length());
        int n = static_cast<int>(p.length());
        if (j == n) {
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false;
            }

            while (j + 1 < n) {
                if (p[j + 1] != '*') {
                    return false;
                }
                j += 2;
            }
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s[i] == p[j] || p[j] == '.') {
            if (j < n - 1 && p[j + 1] == '*') {
                memo[i][j] = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            } else {
                memo[i][j] = dp(s, i + 1, p, j + 1);
            }
        } else {
            if (j < n - 1 && p[j + 1] == '*') {
                memo[i][j] = dp(s, i, p, j + 2);
            } else {
                memo[i][j] = false;
            }
        }

        return memo[i][j];
    }

    void resetMems() {
        memo.clear();
    }


    std::vector<std::vector<int>> memo;
};
}// namespace RegexMatch

TEST(Solution, isMatch) {
    RegexMatch::Solution sln;

    // case1
    std::string s1 = "aa";
    std::string p1 = "a";
    EXPECT_FALSE(sln.isMatch(s1, p1));
    sln.resetMems();

    // case2
    std::string s2 = "aa";
    std::string p2 = "a*";
    EXPECT_TRUE(sln.isMatch(s2, p2));
    sln.resetMems();

    // case3
    std::string s3 = "ab";
    std::string p3 = ".*";
    EXPECT_TRUE(sln.isMatch(s3, p3));
}
