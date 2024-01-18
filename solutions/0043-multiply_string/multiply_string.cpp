//
// Created by richard on 1/18/24.
//
#include "utils.h"

namespace MultiplyString {
class Solution {
public:
    std::string multiply(std::string& num1, std::string& num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = (int) num1.size();
        int n = (int) num2.size();
        std::vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                arr[i + j + 1] += a * b;
            }
        }

        int carry = 0;
        for (int i = m + n - 1; i >= 0; i--) {
            int sum = arr[i] + carry;
            arr[i] = sum % 10;
            carry = sum / 10;
        }

        std::string res;
        int i = arr[0] == 0 ? 1 : 0;
        while (i < m + n) {
            res += std::to_string(arr[i]);
            i++;
        }
        return res;
    }
};
}// namespace MultiplyString

TEST(Solution, multiplyString) {
    MultiplyString::Solution sln;

    // case1
    std::string num1 = "2";
    std::string num2 = "3";
    EXPECT_EQ(sln.multiply(num1, num2), "6");

    // case2
    std::string num3 = "123";
    std::string num4 = "456";
    EXPECT_EQ(sln.multiply(num3, num4), "56088");
}