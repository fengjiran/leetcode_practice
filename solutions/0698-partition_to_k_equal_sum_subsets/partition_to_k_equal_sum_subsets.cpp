//
// Created by richard on 12/27/23.
//
#include "utils.h"

namespace PartitionKSubsets {
class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        if (k > nums.size()) {
            return false;
        }

        int sum = 0;
        for (int v: nums) {
            sum += v;
        }

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        std::vector<int> buckets(k);
        backtrack(nums, 0, buckets, target);
        return canPartition;
    }

    bool canPartitionKSubsets1(std::vector<int>& nums, int k) {
        if (k > nums.size()) {
            return false;
        }

        int sum = 0;
        for (int v: nums) {
            sum += v;
        }

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        used.resize(nums.size());
        backtrack1(nums, 0, 0, k, target);
        return canPartition;
    }

    // from number viewpoint
    // do not pass all test case because of time complexity
    void backtrack(std::vector<int>& nums, int idx, std::vector<int>& buckets, int target) {
        if (idx == nums.size()) {
            for (int v: buckets) {
                if (v != target) {
                    canPartition = false;
                    return;
                }
            }
            canPartition = true;
        } else {
            for (int i = 0; i < buckets.size(); i++) {
                if (buckets[i] + nums[idx] > target) {
                    continue;
                }
                buckets[i] += nums[idx];
                backtrack(nums, idx + 1, buckets, target);
                buckets[i] -= nums[idx];
            }
        }
    }

    // from bucket viewpoint
    void backtrack1(std::vector<int>& nums, int start, int bucket, int k, int target) {
        if (k == 0) {
            canPartition = true;
            return;
        }

        if (bucket == target) {
            backtrack1(nums, 0, 0, k - 1, target);
        }

        for (int i = start; i < nums.size(); i++) {
            if (used[i] || bucket + nums[i] > target) {
                continue;
            }

            used[i] = true;
            bucket += nums[i];
            backtrack1(nums, i + 1, bucket, k, target);
            used[i] = false;
            bucket -= nums[i];
        }
    }

    void resetMems() {
        canPartition = false;
        used.clear();
    }

private:
    bool canPartition{false};
    std::vector<bool> used;
};
}// namespace PartitionKSubsets

TEST(Solution, canPartitionKSubsets) {
    GTEST_SKIP();
    PartitionKSubsets::Solution sln;

    // case1
    std::vector<int> nums1{4, 3, 2, 3, 5, 2, 1};
    int k1 = 4;
    EXPECT_TRUE(sln.canPartitionKSubsets(nums1, k1));

    sln.resetMems();

    // case2
    std::vector<int> nums2{1, 2, 3, 4};
    int k2 = 3;
    EXPECT_FALSE(sln.canPartitionKSubsets(nums2, k2));

    sln.resetMems();

    // case3
    std::vector<int> nums3{3522, 181, 521, 515, 304, 123, 2512, 312, 922, 407, 146, 1932, 4037, 2646, 3871, 269};
    int k3 = 5;
    EXPECT_TRUE(sln.canPartitionKSubsets(nums3, k3));
    sln.resetMems();

    // case4
    std::vector<int> nums4{10, 5, 5, 4, 3, 6, 6, 7, 6, 8, 6, 3, 4, 5, 3, 7};
    int k4 = 8;
    EXPECT_FALSE(sln.canPartitionKSubsets(nums4, k4));
    sln.resetMems();

    // case5
    std::vector<int> nums5{3, 2, 1, 3, 6, 1, 4, 8, 10, 8, 9, 1, 7, 9, 8, 1};
    int k5 = 9;
    EXPECT_FALSE(sln.canPartitionKSubsets(nums5, k5));
}

TEST(Solution, canPartitionKSubsets1) {
    GTEST_SKIP();
    PartitionKSubsets::Solution sln;

    // case1
    std::vector<int> nums1{4, 3, 2, 3, 5, 2, 1};
    int k1 = 4;
    EXPECT_TRUE(sln.canPartitionKSubsets1(nums1, k1));

    sln.resetMems();

    // case2
    std::vector<int> nums2{1, 2, 3, 4};
    int k2 = 3;
    EXPECT_FALSE(sln.canPartitionKSubsets1(nums2, k2));

    sln.resetMems();

    // case3
    std::vector<int> nums3{3522, 181, 521, 515, 304, 123, 2512, 312, 922, 407, 146, 1932, 4037, 2646, 3871, 269};
    int k3 = 5;
    EXPECT_TRUE(sln.canPartitionKSubsets1(nums3, k3));
    sln.resetMems();

    // case4
    std::vector<int> nums4{10, 5, 5, 4, 3, 6, 6, 7, 6, 8, 6, 3, 4, 5, 3, 7};
    int k4 = 8;
    EXPECT_FALSE(sln.canPartitionKSubsets1(nums4, k4));
    sln.resetMems();

    // case5
    std::vector<int> nums5{3, 2, 1, 3, 6, 1, 4, 8, 10, 8, 9, 1, 7, 9, 8, 1};
    int k5 = 9;
    EXPECT_FALSE(sln.canPartitionKSubsets1(nums5, k5));
}
