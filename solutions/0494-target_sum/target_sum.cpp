//
// Created by 赵丹 on 2023/12/24.
//
#include "gtest/gtest.h"

namespace TargetSum {
    class Solution {
    public:
        int findTargetSumWays(std::vector<int> &nums, int target) {
            backtrack(nums, 0, target);
            return res;
        }

        void backtrack(std::vector<int> &nums, int idx, int target) {
            if (idx == nums.size()) {
                if (sum == target) {
                    res++;
                }
                return;
            }

            sum += nums[idx];
            backtrack(nums, idx + 1, target);
            sum -= nums[idx];

            sum -= nums[idx];
            backtrack(nums, idx + 1, target);
            sum += nums[idx];
        }

        void resetMems() {
            sum = 0;
            res = 0;
        }

    private:
        int sum{0};
        int res{0};
    };
}

TEST(Solution, targetSum) {
    TargetSum::Solution sln;
    // case1
    std::vector<int> a1{1, 1, 1, 1, 1};
    int target1 = 3;
    int ans_a1 = 5;

    //case2
    std::vector<int> a2{1};
    int target2 = 1;
    int ans_a2 = 1;

    int res_a1 = sln.findTargetSumWays(a1, target1);
    sln.resetMems();
    int res_a2 = sln.findTargetSumWays(a2, target2);
    EXPECT_EQ(res_a1, ans_a1);
    EXPECT_EQ(res_a2, ans_a2);
}