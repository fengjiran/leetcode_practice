//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace SplitArray {
class Solution {
public:
    int splitArray(std::vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (int num: nums) {
            left = std::max(left, num);
            right += num;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getSplitNums(nums, mid) > k) {
                left = mid + 1;
            } else if (getSplitNums(nums, mid) < k) {
                right = mid;
            } else if (getSplitNums(nums, mid) == k) {
                right = mid;
            }
        }
        return left;
    }

    int getSplitNums(std::vector<int>& nums, int maxSum) {
        int splitNums = 0;
        int sum = 0;
        int i = 0;
        while (i < nums.size()) {
            sum += nums[i];
            if (sum > maxSum) {
                splitNums++;
                sum = 0;
                continue;
            }
            if (i == nums.size() - 1) {
                splitNums++;
            }
            i++;
        }
        return splitNums;
    }
};
}// namespace SplitArray

TEST(Solution, splitArray) {
    SplitArray::Solution sln;

    // case1
    std::vector<int> nums1{7, 2, 5, 10, 8};
    EXPECT_EQ(sln.splitArray(nums1, 2), 18);

    // case2
    std::vector<int> nums2{1, 2, 3, 4, 5};
    EXPECT_EQ(sln.splitArray(nums2, 2), 9);

    // case3
    std::vector<int> nums3{1, 4, 4};
    EXPECT_EQ(sln.splitArray(nums3, 3), 4);
}