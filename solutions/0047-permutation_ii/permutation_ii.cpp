//
// Created by richard on 12/23/23.
//
#include "utils.h"

namespace PermutationII {
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        int n = nums.size();
        visited.resize(n);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return res;
    }

    void backtrack(std::vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            cur.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums);
            cur.pop_back();
            visited[i] = false;
        }
    }

    void resetMems() {
        visited.clear();
        cur.clear();
        res.clear();
    }

private:
    std::vector<bool> visited;
    std::vector<int> cur;
    std::vector<std::vector<int>> res;
};
}// namespace PermutationII

TEST(Solution, permuteUniqueII) {
    PermutationII::Solution sln;
    // case1
    std::vector<int> nums1{1, 1, 2};
    std::vector<std::vector<int>> ans1{{1, 1, 2},
                                       {1, 2, 1},
                                       {2, 1, 1}};

    // case2
    std::vector<int> nums2{1, 2, 3};
    std::vector<std::vector<int>> ans2{{1, 2, 3},
                                       {1, 3, 2},
                                       {2, 1, 3},
                                       {2, 3, 1},
                                       {3, 1, 2},
                                       {3, 2, 1}};

    std::vector<std::vector<int>> res1 = sln.permuteUnique(nums1);
    EXPECT_TRUE(Compare2DVector(res1, ans1));
    sln.resetMems();
    std::vector<std::vector<int>> res2 = sln.permuteUnique(nums2);
    EXPECT_TRUE(Compare2DVector(res2, ans2));
}