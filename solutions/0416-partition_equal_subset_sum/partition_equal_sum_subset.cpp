//
// Created by 赵丹 on 2024/1/10.
//
#include "utils.h"

namespace EqualSumSubsetPartition {
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
    }
};
}// namespace EqualSumSubsetPartition

TEST(Solution, canPartition) {
    EqualSumSubsetPartition::Solution sln;

    // case1
    std::vector<int> nums1{1, 5, 11, 5};
    EXPECT_TRUE(sln.canPartition(nums1));

    // case2
    std::vector<int> nums2{1, 2, 3, 5};
    EXPECT_FALSE(sln.canPartition(nums2));
}