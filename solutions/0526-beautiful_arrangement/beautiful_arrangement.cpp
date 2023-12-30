//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace BeautifulArrangement {
class Solution {
public:
    int countArrangement(int n) {
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int idx) {
        if (idx == n) {
            res++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (std::find(track.begin(), track.end(), i) != track.end()) {
                continue;
            }
            if (i % (idx + 1) == 0 || (idx + 1) % i == 0) {
                track.push_back(i);
                backtrack(n, idx + 1);
                track.pop_back();
            }
        }
    }

    void resetMems() {
        res = 0;
        track.clear();
    }

    std::vector<int> track;
    int res{0};
};
}// namespace BeautifulArrangement

TEST(Solution, countArrangement) {
    BeautifulArrangement::Solution sln;

    // case1
    EXPECT_EQ(sln.countArrangement(2), 2);

    sln.resetMems();

    // case2
    EXPECT_EQ(sln.countArrangement(1), 1);
}