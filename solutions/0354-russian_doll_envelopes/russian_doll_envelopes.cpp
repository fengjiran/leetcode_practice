//
// Created by 赵丹 on 2024/1/5.
//
#include "utils.h"

namespace {
class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        auto cmp = [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        };

        std::sort(envelopes.begin(), envelopes.end(), cmp);
        std::vector<int> height;
        height.reserve(envelopes.size());
        for (auto& item: envelopes) {
            height.push_back(item[1]);
        }
        return lis1(height);
    }

    static int lis(std::vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> top(n);
        int piles = 0;
        for (int poker: nums) {
            int left = 0;
            int right = piles;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (top[mid] > poker) {
                    right = mid;
                } else if (top[mid] < poker) {
                    left = mid + 1;
                } else if (top[mid] == poker) {
                    right = mid;
                }
            }
            if (left == piles) {
                piles++;
            }
            top[left] = poker;
        }
        return piles;
    }

    // use dp
    static int lis1(std::vector<int>& nums) {
        int n = (int) nums.size();
        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
}// namespace

TEST(Solution, maxEnvelopes) {
    ::Solution sln;

    // case1
    std::vector<std::vector<int>> nums1{{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    EXPECT_EQ(sln.maxEnvelopes(nums1), 3);
}