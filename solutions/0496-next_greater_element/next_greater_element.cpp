//
// Created by richard on 1/20/24.
//
#include "utils.h"

namespace NextGreatElementI {
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> greater = nextGreaterElement(nums2);
        std::unordered_map<int, int> greaterMap;
        for (int i = 0; i < nums2.size(); i++) {
            greaterMap[nums2[i]] = greater[i];
        }

        std::vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = greaterMap[nums1[i]];
        }
        return res;
    }

    std::vector<int> nextGreaterElement(std::vector<int>& nums) {
        int n = (int) nums.size();
        std::vector<int> res(n);
        std::stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            res[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};
}// namespace NextGreatElementI

TEST(Solution, nextGreaterElementI) {
    NextGreatElementI::Solution sln;

    // case1
    std::vector<int> num1{4, 1, 2};
    std::vector<int> num2{1, 3, 4, 2};
    std::vector<int> expect{-1, 3, -1};
    std::vector<int> res = sln.nextGreaterElement(num1, num2);
    std::sort(expect.begin(), expect.end());
    std::sort(res.begin(), res.end());
    EXPECT_EQ(expect.size(), res.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(expect[i], res[i]);
    }
}