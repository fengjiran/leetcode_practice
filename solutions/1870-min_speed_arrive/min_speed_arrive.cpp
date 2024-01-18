//
// Created by richard on 1/18/24.
//
#include "utils.h"

namespace MinSpeedArrive {
class Solution {
public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            double times = getTime(dist, mid);
            if (times > hour) {
                left = mid + 1;
            } else if (times < hour) {
                right = mid;
            } else {
                right = mid;
            }
        }
        return left == 1e7 + 1 ? -1 : left;
    }

    double getTime(std::vector<int>& dist, int speed) {
        double times = 0;
        int n = (int) dist.size();
        for (int i = 0; i < n - 1; i++) {
            times += dist[i] / speed;
            if (dist[i] % speed != 0) {
                times++;
            }
        }
        times += dist[n - 1] * 1.0 / speed;
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