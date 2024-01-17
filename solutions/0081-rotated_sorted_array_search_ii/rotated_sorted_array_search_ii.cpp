//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace RotatedSortedArraySearchII {
class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[left]) {
                left++;
            } else if (nums[mid] > nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[left]) {
                if (target <= nums[right - 1] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return false;
    }
};
}// namespace RotatedSortedArraySearchII

TEST(Solution, rotatedSortedArraySearchII) {
    RotatedSortedArraySearchII::Solution sln;

    // case1
    std::vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    EXPECT_TRUE(sln.search(nums, 0));
    EXPECT_FALSE(sln.search(nums, 3));
}