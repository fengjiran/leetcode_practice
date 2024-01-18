//
// Created by richard on 1/18/24.
//
#include "utils.h"

namespace MaxNumRemove {
class Solution {
public:
    int maximumRemovals(std::string& s, std::string& p, std::vector<int>& removable) {
        int left = 0;
        int right = removable.size() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(s, p, removable, mid)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }

    bool check(std::string& s, std::string& p, std::vector<int>& removable, int mid) {
        std::unordered_set<int> ids;
        for (int k = 0; k < mid; k++) {
            ids.insert(removable[k]);
        }

        int i = 0;
        int j = 0;
        while (i < s.size() && j < p.size()) {
            if (ids.count(i) == 0 && s[i] == p[j]) {
                j++;
            }
            i++;
        }
        return j == p.size();
    }
};
}// namespace MaxNumRemove

TEST(Solution, maximumRemovals) {
    MaxNumRemove::Solution sln;

    // case1
    std::string s1 = "abcacb";
    std::string p1 = "ab";
    std::vector<int> removbale1{3, 1, 0};
    EXPECT_EQ(sln.maximumRemovals(s1, p1, removbale1), 2);

    // case2
    std::string s2 = "abcbddddd";
    std::string p2 = "abcd";
    std::vector<int> removbale2{3, 2, 1, 4, 5, 0};
    EXPECT_EQ(sln.maximumRemovals(s2, p2, removbale2), 1);
}