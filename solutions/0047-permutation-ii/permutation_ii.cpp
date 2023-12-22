//
// Created by richard on 12/23/23.
//
#include "gtest/gtest.h"

using std::vector;
using std::sort;
using std::stable_sort;
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

        static bool compareVector(vector<vector<int>> &nums1, vector<vector<int>> &nums2) {
            stable_sort(nums1.begin(), nums1.end());
            stable_sort(nums2.begin(), nums2.end());
            if (nums1.size() != nums2.size()) {
                return false;
            }

            for (int i = 0; i < nums1.size(); i++) {
                bool isEqual = std::equal(nums1[i].begin(), nums1[i].end(),
                                          nums2[i].begin(), nums2[i].end());
                if (!isEqual) {
                    return false;
                }
            }
            return true;
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
    EXPECT_TRUE(sln.compareVector(res1, ans1));
    sln.resetMems();
    vector<vector<int>> res2 = sln.permuteUnique(nums2);
    EXPECT_TRUE(sln.compareVector(res2, ans2));
}