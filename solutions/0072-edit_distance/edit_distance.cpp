//
// Created by 赵丹 on 2024/1/6.
//
#include "utils.h"

namespace EditDistance {
class Solution {
public:
    int minDistance(std::string& word1, std::string& word2) {
        int m = word1.size();
        int n = word2.size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
        return dp(word1, m - 1, word2, n - 1, memo);
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

    // case2
}