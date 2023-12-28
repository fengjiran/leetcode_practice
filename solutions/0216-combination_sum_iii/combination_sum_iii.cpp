//
// Created by richard on 12/27/23.
//
#include "utils.h"

namespace CombinationSumIII {
class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return res;
    }

    void backtrack(int k, int n, int start) {
        if (sum == n && track.size() == k) {
            res.push_back(track);
            return;
        }

        if (track.size() > k) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (std::find(track.begin(), track.end(), i) != track.end()) {
                continue;
            }

            if (sum + i > n) {
                continue;
            }

            track.push_back(i);
            sum += i;
            backtrack(k, n, i + 1);
            track.pop_back();
            sum -= i;
        }
    }

    void resetMems() {
        sum = 0;
        track.clear();
        res.clear();
    }

private:
    int sum{0};
    std::vector<int> track;
    std::vector<std::vector<int>> res;
};
}// namespace CombinationSumIII

TEST(Solution, combinationSum3) {
    CombinationSumIII::Solution sln;
    // case1
    std::vector<std::vector<int>> expect1 = {{1, 2, 4}};
    std::vector<std::vector<int>> res1 = sln.combinationSum3(3, 7);
    EXPECT_TRUE(Compare2DVector(res1, expect1));
    sln.resetMems();

    // case2
    std::vector<std::vector<int>> expect2 = {{1, 2, 6},
                                             {1, 3, 5},
                                             {2, 3, 4}};
    std::vector<std::vector<int>> res2 = sln.combinationSum3(3, 9);
    EXPECT_TRUE(Compare2DVector(res2, expect2));
    sln.resetMems();

    // case3
    std::vector<std::vector<int>> expect3;
    std::vector<std::vector<int>> res3 = sln.combinationSum3(4, 1);
    EXPECT_TRUE(Compare2DVector(res3, expect3));
}