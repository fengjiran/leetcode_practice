//
// Created by 赵丹 on 2023/12/28.
//
#include "utils.h"

namespace BinaryWatch {
class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        //
    }

    void backtrack(int num, int start, int hour, int minute) {
        //

    }

private:
    std::string cur;
    std::vector<std::string> res;
    std::vector<int> times{8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
};
}// namespace BinaryWatch


TEST(Solution, readBinaryWatch) {
    BinaryWatch::Solution sln;

    // case1
    std::vector<std::string> expect1{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};

    // case2
    std::vector<std::string> expect2{};
}