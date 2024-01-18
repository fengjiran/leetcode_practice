//
// Created by richard on 1/18/24.
//
#include "utils.h"

namespace MinSpeedArrive {
class Solution {
public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
    }

    int getTime(std::vector<int>& dist, int speed) {
        int times = 0;
        for (int d: dist) {
            times += d / speed;
            if (d % speed != 0) {
                times++;
            }
        }
        return times;
    }
};
}// namespace MinSpeedArrive

TEST(Solution, minSpeedOnTime) {
    MinSpeedArrive::Solution sln;

    // case1
    std::vector<int> dist1{1, 3, 2};
    EXPECT_EQ(sln.minSpeedOnTime(dist1, 6), 1);

    // case2
    EXPECT_EQ(sln.minSpeedOnTime(dist1, 2.7), 3);

    // case3
    EXPECT_EQ(sln.minSpeedOnTime(dist1, 1.9), -1);
}