//
// Created by 赵丹 on 2023/12/30.
//
#include "utils.h"
namespace PalindromePartition {
class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(std::string& s, int pos) {
        int n = s.length();
        if (pos == n) {
            res.push_back(track);
            return;
        }
        for (int i = 1; i <= n - pos; i++) {
            if (isPalindrome(s, pos, pos + i - 1)) {
                track.push_back(s.substr(pos, i));
                backtrack(s, pos + i);
                track.pop_back();
            }
        }
    }

    std::vector<std::string> track;
    std::vector<std::vector<std::string>> res;
};
}// namespace PalindromePartition

TEST(Solution, palindromePartition) {
    PalindromePartition::Solution sln;

    // case1
    std::string s1 = "aab";
    std::vector<std::vector<std::string>> expect1 = {
            {"a", "a", "b"},
            {"aa", "b"}};

    std::vector<std::vector<std::string>> res1 = sln.partition(s1);
    EXPECT_EQ(res1.size(), expect1.size());
    for (int i = 0; i < res1.size(); i++) {
        EXPECT_TRUE(Compare2DString(res1[i], expect1[i]));
    }
}