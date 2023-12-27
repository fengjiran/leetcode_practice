//
// Created by richard on 12/27/23.
//
#include "utils.h"

namespace AdditiveNumber {
    class Solution {
    public:
        bool isAdditiveNumber(std::string num) {
            int n = num.size();
            if (n < 3) {
                return false;
            }

            for (int secondStart = 1; secondStart < n - 1; secondStart++) {
                if (num[0] == '0' && secondStart != 1) {
                    break;
                }
                for (int secondEnd = secondStart; secondEnd < n - 1; secondEnd++) {
                    if (num[secondStart] == '0' && secondStart != secondEnd) {
                        break;
                    }
                    if (isValid(num, secondStart, secondEnd)) {
                        return true;
                    }
                }
            }

            return false;
        }

        static std::string stringAdd(std::string &s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
            std::string third;
            int carry = 0;
            int cur;
            while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
                cur = carry;
                if (firstEnd >= firstStart) {
                    cur += (s[firstEnd] - '0');
                    firstEnd--;
                }

                if (secondEnd >= secondStart) {
                    cur += (s[secondEnd] - '0');
                    secondEnd--;
                }

                carry = cur / 10;
                cur = cur % 10;
                third += (char) (cur + '0');
            }
            std::reverse(third.begin(), third.end());
            return third;
        }

        bool isValid(std::string &num, int secondStart, int secondEnd) {
            size_t n = num.size();
            int firstStart = 0;
            int firstEnd = secondStart - 1;
            while (secondEnd < n) {
                std::string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
                int thirdStart = secondEnd + 1;
                int thirdEnd = secondEnd + third.size();
                if (thirdEnd >= n || num.substr(thirdStart, thirdEnd - thirdStart + 1) != third) {
                    break;
                }

                if (thirdEnd == n - 1) {
                    return true;
                }

                firstStart = secondStart;
                firstEnd = secondEnd;
                secondStart = thirdStart;
                secondEnd = thirdEnd;
            }
            return false;
        }
    };
}

TEST(Solution, isAdditiveNumber) {
    AdditiveNumber::Solution sln;

    // case1
    std::string num1 = "112358";
    EXPECT_TRUE(sln.isAdditiveNumber(num1));

    // case2
    std::string num2 = "199100199";
    EXPECT_TRUE(sln.isAdditiveNumber(num2));

}
