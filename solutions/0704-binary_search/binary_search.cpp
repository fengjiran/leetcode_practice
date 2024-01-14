//
// Created by richard on 1/14/24.
//
#include "utils.h"

namespace BinarySearch {
class Solution {
public:
    // find left boundary
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] == target) {
                right = mid;
            }
        }

        if (left == nums.size()) {
            return -1;
        }
        return nums[left] == target ? left : -1;
    }
};
}// namespace BinarySearch

TEST(Solution, binarySearch) {
    BinarySearch::Solution sln;

    // case1
    std::vector<int> nums1{-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    EXPECT_EQ(sln.search(nums1, target1), 4);

    // case2
    std::vector<int> nums2{-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    EXPECT_EQ(sln.search(nums2, target2), -1);
}