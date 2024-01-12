//
// Created by richard on 1/13/24.
//
#include "utils.h"

namespace AllGraphPath {
class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }

    void traverse(std::vector<std::vector<int>>& graph, int i) {
        path.push_back(i);
        if (i == graph.size() - 1) {
            res.push_back(path);
        }
        for (int it: graph[i]) {
            traverse(graph, it);
        }
        path.pop_back();
    }

    std::vector<int> path;
    std::vector<std::vector<int>> res;
};
}// namespace AllGraphPath

TEST(Solution, allPathsSourceTarget) {
    AllGraphPath::Solution sln;

    // case1
    std::vector<std::vector<int>> graph1{{1, 2}, {3}, {3}, {}};
    std::vector<std::vector<int>> expect1{{0, 1, 3}, {0, 2, 3}};
    std::vector<std::vector<int>> res1 = sln.allPathsSourceTarget(graph1);
    EXPECT_TRUE(Compare2DVector(res1, expect1));
}