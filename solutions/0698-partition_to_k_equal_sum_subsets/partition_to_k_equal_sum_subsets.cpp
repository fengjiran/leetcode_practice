//
// Created by richard on 12/27/23.
//
#include "utils.h"

namespace PartitionKSubsets {
    class Solution {
        bool canPartitionKSubsets(std::vector<int> &nums, int k) {
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

        void backtrack(std::vector<int> &nums, int idx, std::vector<int> &buckets, int target) {
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

        bool canPartition{false};
    };
}

TEST(Solution, canPartitionKSubsets) {
    //
}
