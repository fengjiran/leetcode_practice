//
// Created by richard on 1/9/24.
//
#include "utils.h"

namespace MinPathSum {
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        //
    }
};
}// namespace MinPathSum

TEST(Solution, minPathSum) {
    MinPathSum::Solution sln;

    // case1
    std::vector<std::vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    EXPECT_EQ(sln.minPathSum(grid1), 7);

    // case2
    std::vector<std::vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(sln.minPathSum(grid2), 12);
}