//
// Created by richard on 1/12/24.
//
#include "utils.h"

namespace SuperEggDrop {
class Solution {
public:
    int superEggDrop(int k, int n) {
        memo.resize(k + 1, std::vector<int>(n + 1, -666));
        return dp(k, n);
    }

    int dp(int k, int n) {
        if (k == 1) {
            return n;
        }

        if (n == 0) {
            return 0;
        }

        if (memo[k][n] != -666) {
            return memo[k][n];
        }

        int res = std::numeric_limits<int>::max();
        //        for (int i = 1; i <= n; i++) {
        //            res = std::min(res, std::max(dp(k, n - i), dp(k - 1, i - 1)) + 1);
        //        }

        // use binary search optimize runtime
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int broken = dp(k - 1, mid - 1);
            int no_broken = dp(k, n - mid);
            if (broken > no_broken) {
                high = mid - 1;
                res = std::min(res, broken + 1);
            } else {
                low = mid + 1;
                res = std::min(res, no_broken + 1);
            }
        }
        memo[k][n] = res;
        return res;
    }

    std::vector<std::vector<int>> memo;
};
}// namespace SuperEggDrop

TEST(Solution, superEggDrop) {
    SuperEggDrop::Solution sln;

    // case1
    EXPECT_EQ(sln.superEggDrop(1, 2), 2);
    sln.memo.clear();

    // case2
    EXPECT_EQ(sln.superEggDrop(2, 6), 3);
    sln.memo.clear();

    // case3
    EXPECT_EQ(sln.superEggDrop(3, 14), 4);
    sln.memo.clear();

    // case4
    EXPECT_EQ(sln.superEggDrop(4, 10000), 23);
}