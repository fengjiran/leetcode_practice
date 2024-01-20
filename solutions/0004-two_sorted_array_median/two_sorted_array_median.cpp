//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace TwoSortedArrayMedian {
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        return 0;
    }
};
}// namespace TwoSortedArrayMedian

TEST(Solution, findMedianSortedArrays) {
    GTEST_SKIP();
    TwoSortedArrayMedian::Solution sln;

    // case1
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    EXPECT_DOUBLE_EQ(sln.findMedianSortedArrays(nums1, nums2), 2.0);
}