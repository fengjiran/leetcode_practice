//
// Created by 赵丹 on 2023/12/27.
//
#include "utils.h"

namespace LetterCasePermutation {
class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(std::string& s, int start) {
        if (start == s.size()) {
            res.push_back(track);
            return;
        }

        char c = s[start];
        if (!std::isalpha(c)) {
            track += c;
            backtrack(s, start + 1);
            track.pop_back();
        } else {
            track += (char) std::toupper(c);
            backtrack(s, start + 1);
            track.pop_back();

            track += (char) std::tolower(c);
            backtrack(s, start + 1);
            track.pop_back();
        }
    }

    void resetMems() {
        track.clear();
        res.clear();
    }

private:
    std::string track;
    std::vector<std::string> res;
};
}// namespace LetterCasePermutation

TEST(Solution, letterCasePermutation) {
    LetterCasePermutation::Solution sln;
    // case1
    std::string s1 = "a1b2";
    std::vector<std::string> expect1 = {"a1b2", "a1B2", "A1b2", "A1B2"};
    std::vector<std::string> res1 = sln.letterCasePermutation(s1);
    EXPECT_TRUE(Compare2DString(res1, expect1));

    sln.resetMems();

    // case2
    std::string s2 = "3z4";
    std::vector<std::string> expect2 = {"3z4", "3Z4"};
    std::vector<std::string> res2 = sln.letterCasePermutation(s2);
    EXPECT_TRUE(Compare2DString(res2, expect2));
}