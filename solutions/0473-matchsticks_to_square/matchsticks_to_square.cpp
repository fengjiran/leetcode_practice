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
        sides.resize(4);
        return backtrack(matchsticks, 0, side_len);
    }

    bool backtrack(std::vector<int>& matchsticks, int idx, int target) {
        if (idx == matchsticks.size()) {
            return std::all_of(sides.begin(), sides.end(), [=](int i) { return i == target; });
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] > target || (i > 0 && sides[i] == sides[i - 1])) {
                continue;
            }
            sides[i] += matchsticks[idx];
            if (backtrack(matchsticks, idx + 1, target)) {
                return true;
            }
            sides[i] -= matchsticks[idx];
        }
        return false;
    }

    void resetMems() {
        sides.clear();
    }

private:
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
    std::vector<int> nums2{3, 3, 3, 3, 4};
    EXPECT_FALSE(sln.makesquare(nums2));

    // case3
    std::vector<int> nums3{5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3};
    EXPECT_TRUE(sln.makesquare(nums3));

    // case4
    std::vector<int> nums4{6122053, 1031956, 460065, 3996684, 3891947, 1839190, 6127621, 8855952, 8835594, 3425930, 4189081, 7596722, 876208, 7952011, 9676846};
    EXPECT_FALSE(sln.makesquare(nums4));
}