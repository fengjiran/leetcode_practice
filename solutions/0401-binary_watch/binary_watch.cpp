//
// Created by 赵丹 on 2023/12/28.
//
#include "utils.h"

namespace BinaryWatch {
class Solution {
public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        backtrack(turnedOn, 0, 0, 0);
        return res;
    }

    void backtrack(int total, int start, int hour, int minute) {
        if (total == 0) {
            if (hour > 11 || minute > 59) {
                return;
            }

            // hours
            std::string cur = std::to_string(hour) + ":";

            // minutes
            if (minute < 10) {
                cur += "0";
            }
            cur += std::to_string(minute);
            res.push_back(cur);
            return;
        }

        for (int i = start; i < times.size(); i++) {
            if (i < 4) {
                hour += times[i];
            } else {
                minute += times[i];
            }
            backtrack(total - 1, i + 1, hour, minute);
            if (i < 4) {
                hour -= times[i];
            } else {
                minute -= times[i];
            }
        }
    }

    void resetMems() {
        res.clear();
    }

private:
    std::vector<std::string> res;
    std::vector<int> times{8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
};
}// namespace BinaryWatch


TEST(Solution, readBinaryWatch) {
    BinaryWatch::Solution sln;

    // case1
    std::vector<std::string> expect1{"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
    std::vector<std::string> res1 = sln.readBinaryWatch(1);
    EXPECT_TRUE(Compare2DString(res1, expect1));
    sln.resetMems();

    // case2
    std::vector<std::string> expect2{};
    std::vector<std::string> res2 = sln.readBinaryWatch(9);
    EXPECT_TRUE(Compare2DString(res2, expect2));
}