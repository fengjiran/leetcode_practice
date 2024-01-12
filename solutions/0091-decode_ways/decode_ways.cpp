//
// Created by richard on 1/12/24.
//
#include "utils.h"

namespace DecodeWays {
class Solution {
public:
    int numDecodings(const std::string& s) {
        int n = static_cast<int>(s.size());
        memo.resize(n + 1, -1);
        return dp(s, n);
    }

    int dp(const std::string& s, int i) {
        if (i == 0) {
            memo[i] = 1;
            return 1;
        }

        if (i == 1) {
            memo[i] = s[0] == '0' ? 0 : 1;
            return memo[i];
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        char c = s[i - 1];
        char d = s[i - 2];
        int res = 0;
        if (c >= '1' && c <= '9') {
            res += dp(s, i - 1);
        }

        if (d == '1' || (d == '2' && c <= '6')) {
            res += dp(s, i - 2);
        }

        memo[i] = res;

        return memo[i];
    }

    std::vector<int> memo;
};
}// namespace DecodeWays

TEST(Solution, numDecodings) {
    DecodeWays::Solution sln;

    // case1
    EXPECT_EQ(sln.numDecodings("12"), 2);

    sln.memo.clear();
    // case2
    EXPECT_EQ(sln.numDecodings("226"), 3);

    sln.memo.clear();
    // case3
    EXPECT_EQ(sln.numDecodings("06"), 0);
}