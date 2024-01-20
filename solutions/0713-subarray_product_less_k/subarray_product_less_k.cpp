//
// Created by richard on 1/20/24.
//
#include "utils.h"

namespace SubarrayProductLessK {
class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int product = 1;
        int res = 0;
        while (right < nums.size()) {
            product *= nums[right++];
            while (product >= k && left < right) {
                product /= nums[left++];
            }
            res += right - left;
        }
        return res;
    }
};
}// namespace SubarrayProductLessK

TEST(Solution, numSubarrayProductLessThanK) {
    SubarrayProductLessK::Solution sln;

    // case1
    std::vector<int> nums1{10, 5, 2, 6};
    int k1 = 100;
    EXPECT_EQ(sln.numSubarrayProductLessThanK(nums1, k1), 8);

    // case2
    std::vector<int> nums2{1, 2, 3};
    int k2 = 0;
    EXPECT_EQ(sln.numSubarrayProductLessThanK(nums2, k2), 0);
}