//
// Created by 赵丹 on 2023/12/31.
//
#include "utils.h"

namespace OpenLock {
class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::queue<std::string> q;
        std::unordered_set<std::string> used;
        if (std::find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }
        q.emplace("0000");
        used.insert("0000");
        for (const auto& deadend: deadends) {
            used.insert(deadend);
        }

        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                std::string cur = q.front();
                q.pop();
                if (cur == target) {
                    return step;
                }

                for (int j = 0; j < 4; j++) {
                    std::string up = pushUp(cur, j);
                    if (used.count(up) == 0) {
                        q.push(up);
                        used.insert(up);
                    }

                    std::string down = pushDown(cur, j);
                    if (used.count(down) == 0) {
                        q.push(down);
                        used.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    std::string pushUp(std::string s, int i) {
        if (s[i] == '9') {
            s[i] = '0';
        } else {
            s[i] += 1;
        }
        return s;
    }

    std::string pushDown(std::string s, int i) {
        if (s[i] == '0') {
            s[i] = '9';
        } else {
            s[i] -= 1;
        }
        return s;
    }
};
}// namespace OpenLock

TEST(Solution, openLock) {
    OpenLock::Solution sln;

    // case1
    std::vector<std::string> deadends1 = {"0201", "0101", "0102", "1212", "2002"};
    std::string target1 = "0202";
    EXPECT_EQ(sln.openLock(deadends1, target1), 6);

    // case2
    std::vector<std::string> deadends2 = {"8888"};
    std::string target2 = "0009";
    EXPECT_EQ(sln.openLock(deadends2, target2), 1);

    // case3
    std::vector<std::string> deadends3 = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    std::string target3 = "8888";
    EXPECT_EQ(sln.openLock(deadends3, target3), -1);
}