//
// Created by richard on 12/28/23.
//
#include "utils.h"

namespace MatchsticksToSquare {
class Solution {
public:
    bool makesquare(std::vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) {
            return false;
        }

        int sum = 0;
        for (int v: matchsticks) {
            sum += v;
        }

        if (sum % 4 != 0) {
            return false;
        }

        int side_len = sum / 4;
        std::sort(matchsticks.begin(), matchsticks.end());

        used.resize(n);
        sides.resize(4);
        backtrack(matchsticks, side_len, 0);
        return found;
    }

    void backtrack(std::vector<int>& matchsticks, int side_len, int side_id) {
        if (side_id == 4) {
            for (int v: sides) {
                if (v != side_len) {
                    found = false;
                    return;
                }
            }
            found = true;
            return;
        }

        for (int i = 0; i < matchsticks.size(); i++) {
            if (used[i] || sides[side_id] + matchsticks[i] > side_len) {
                continue;
            }

            if (sides[side_id] + matchsticks[i] == side_len) {
                side_id += 1;
            }
            used[i] = true;
            sides[side_id] += matchsticks[i];
            backtrack(matchsticks, side_len, side_id);
            used[i] = false;
            sides[side_id] -= matchsticks[i];
        }
    }

    void resetMems() {
        found = false;
        used.clear();
        sides.clear();
    }

private:
    bool found{false};
    std::vector<bool> used;
    std::vector<int> sides;
};
}// namespace MatchsticksToSquare

TEST(Solution, makesquare) {
    MatchsticksToSquare::Solution sln;

    // case1
    std::vector<int> nums1{1, 1, 2, 2, 2};
    EXPECT_TRUE(sln.makesquare(nums1));
    sln.resetMems();

    // case2
//    std::vector<int> nums2{3, 3, 3, 3, 4};
//    EXPECT_FALSE(sln.makesquare(nums2));
}