//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace RotatedSortedArraySearch {
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int) nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[0]) {
                if (nums[mid] > target && target >= nums[left]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};
}// namespace RotatedSortedArraySearch

TEST(Solution, rotatedSortedArraySearch) {
    RotatedSortedArraySearch::Solution sln;

    // case1
    std::vector<int> nums1{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(sln.search(nums1, 0), 4);

    // case2
    std::vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
    EXPECT_EQ(sln.search(nums2, 3), -1);

    // case3
    std::vector<int> nums3{1};
    EXPECT_EQ(sln.search(nums3, 0), -1);
}