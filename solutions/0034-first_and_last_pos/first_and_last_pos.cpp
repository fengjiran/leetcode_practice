//
// Created by richard on 1/17/24.
//
#include "utils.h"

namespace FirstAndLastPos {
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int leftBound = findLeftBound(nums, target);
        int rightBound;
        if (leftBound == -1) {
            rightBound = -1;
        } else {
            rightBound = findRightBound(nums, target);
        }
        return {leftBound, rightBound};
    }

    int findLeftBound(std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid;
            }
        }

        if (left == nums.size()) {
            return -1;
        }

        return nums[left] == target ? left : -1;
    }

    int findRightBound(std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int) nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (left - 1 < 0) {
            return -1;
        }

        return nums[left - 1] == target ? left - 1 : -1;
    }
};
}// namespace FirstAndLastPos

TEST(Solution, searchRange) {
    FirstAndLastPos::Solution sln;

    // case1
    std::vector<int> nums1{5, 7, 7, 8, 8, 10};
    std::vector<int> expect1{3, 4};
    std::vector<int> res1 = sln.searchRange(nums1, 8);
    EXPECT_EQ(res1[0], expect1[0]);
    EXPECT_EQ(res1[1], expect1[1]);
}