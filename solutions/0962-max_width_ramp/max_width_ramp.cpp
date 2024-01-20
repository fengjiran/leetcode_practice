//
// Created by 赵丹 on 2024/1/20.
//
#include "utils.h"

namespace MaxWidthRamp {
class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = (int) nums.size();
        std::stack<int> stk;
        stk.push(0);
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }

        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                res = std::max(res, i - stk.top());
                stk.pop();
            }
            if (stk.empty()) {
                break;
            }
        }
        return res;
    }
};
}// namespace MaxWidthRamp

TEST(Solution, maxWidthRamp) {
    MaxWidthRamp::Solution sln;

    // case1
    std::vector<int> nums1{6, 0, 8, 2, 1, 5};
    EXPECT_EQ(sln.maxWidthRamp(nums1), 4);

    // case2
    std::vector<int> nums2{9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    EXPECT_EQ(sln.maxWidthRamp(nums2), 7);
}