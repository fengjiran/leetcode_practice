//
// Created by 赵丹 on 2024/1/13.
//
#include "utils.h"

namespace ConnectedComponent {
class Solution {
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        UnionFind uf(n);
        for (std::vector<int>& it: edges) {
            uf.unionNodes(it[0], it[1]);
        }
        return uf.getCount();
    }
};
}// namespace ConnectedComponent

TEST(Solution, countComponents) {
    ConnectedComponent::Solution sln;

    // case1
    std::vector<std::vector<int>> edges1{{0, 1}, {1, 2}, {3, 4}};
    EXPECT_EQ(sln.countComponents(5, edges1), 2);

    // case2
    std::vector<std::vector<int>> edges2{{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    EXPECT_EQ(sln.countComponents(5, edges2), 1);
}