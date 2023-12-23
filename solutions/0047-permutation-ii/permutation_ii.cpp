//
// Created by richard on 12/23/23.
//
#include "gtest/gtest.h"
#include "utils.h"

using std::vector;
using std::sort;

namespace PermutationII {
    class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int> &nums) {
            int n = nums.size();
            visited.resize(n);
            sort(nums.begin(), nums.end());
            backtrack(nums);
            return res;
        }

        void backtrack(vector<int> &nums) {
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
        vector<bool> visited;
        vector<int> cur;
        vector<vector<int>> res;
    };
}

TEST(Solution, permuteUniqueII) {
    PermutationII::Solution sln;
    // case1
    vector<int> nums1{1, 1, 2};
    vector<vector<int>> ans1{{1, 1, 2},
                             {1, 2, 1},
                             {2, 1, 1}};

    // case2
    vector<int> nums2{1, 2, 3};
    vector<vector<int>> ans2{{1, 2, 3},
                             {1, 3, 2},
                             {2, 1, 3},
                             {2, 3, 1},
                             {3, 1, 2},
                             {3, 2, 1}};

    vector<vector<int>> res1 = sln.permuteUnique(nums1);
    EXPECT_TRUE(Compare2DVector(res1, ans1));
    sln.resetMems();
    vector<vector<int>> res2 = sln.permuteUnique(nums2);
    EXPECT_TRUE(Compare2DVector(res2, ans2));
}