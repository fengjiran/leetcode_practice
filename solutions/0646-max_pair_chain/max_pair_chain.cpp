//
// Created by 赵丹 on 2024/1/28.
//
#include "utils.h"

namespace MaxPairChain {
class Solution {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end());
        int n = (int) pairs.size();
        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 0;
        for (int it: dp) {
            res = std::max(res, it);
        }
        return res;
    }
};
}// namespace MaxPairChain

TEST(Solution, findLongestChain) {
    MaxPairChain::Solution sln;

    // case1
    std::vector<std::vector<int>> pairs1{{1, 2}, {2, 3}, {3, 4}};
    EXPECT_EQ(sln.findLongestChain(pairs1), 2);

    // case2
    std::vector<std::vector<int>> pairs2{{1, 2}, {7, 8}, {4, 5}};
    EXPECT_EQ(sln.findLongestChain(pairs2), 3);
}