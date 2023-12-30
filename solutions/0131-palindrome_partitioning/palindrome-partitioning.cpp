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
                backtrack(s, pos + 1);
                track.pop_back();
            }
        }
    }

    static bool isPalindrome(const std::string& s, int left, int right) {
        int n = (right - left + 1) / 2;
        for (int i = left; i < left + n; i++) {
            if (s[i] != s[right + left - i]) {
                return false;
            }
        }
        return true;
    }

    std::vector<std::string> track;
    std::vector<std::vector<std::string>> res;
};
}// namespace PalindromePartition

TEST(Solution, palindromePartition) {
    PalindromePartition::Solution sln;

    // case1
    std::string s1 = "aab";

    // case2
    std::string s2 = "a";
}