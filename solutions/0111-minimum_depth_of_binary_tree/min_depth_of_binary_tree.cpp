//
// Created by 赵丹 on 2023/12/31.
//
#include "utils.h"
namespace MinBinaryTreeDepth {
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {
                    return depth;
                }
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
}// namespace MinBinaryTreeDepth

TEST(Solution, minBinaryTreeDepth) {
    MinBinaryTreeDepth::Solution sln;

    // case1
    std::vector<int> nums1 = {3, 9, 20, null, null, 15, 7};
    TreeNode* root1 = BuildBinaryTree(nums1);
    EXPECT_EQ(sln.minDepth(root1), 2);

    // case2
    std::vector<int> nums2 = {2, null, 3, null, 4, null, 5, null, 6};
    TreeNode* root2 = BuildBinaryTree(nums2);
    EXPECT_EQ(sln.minDepth(root2), 5);
}