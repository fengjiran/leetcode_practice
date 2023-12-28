//
// Created by 赵丹 on 2023/12/24.
//
#include "utils.h"

namespace TwoSum {
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (value2index.find(target - nums[i]) != value2index.end()) {
                return {i, value2index[target - nums[i]]};
            }
            value2index[nums[i]] = i;
        }
        return {};
    }

private:
    std::unordered_map<int, int> value2index;
};
}// namespace TwoSum

TEST(Solution, twoSum) {
    TwoSum::Solution sln;
    // case1
    std::vector<int> a{2, 7, 11, 15};
    int target = 9;
    std::vector<int> ans_a{0, 1};

    std::vector<int> res_a = sln.twoSum(a, target);
    EXPECT_EQ(res_a.size(), ans_a.size());
    for (int item: res_a) {
        EXPECT_TRUE(std::find(ans_a.begin(), ans_a.end(), item) != ans_a.end());
    }
}