//
// Created by richard on 1/12/24.
//
#include "utils.h"

namespace CompleteBinaryTreeNodes {
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode* leftTree = root->left;
        TreeNode* rightTree = root->right;
        int leftHeight = 0;
        int rightHeight = 0;

        while (leftTree) {
            leftTree = leftTree->left;
            leftHeight++;
        }

        while (rightTree) {
            rightTree = rightTree->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            return static_cast<int>(std::pow(2, leftHeight + 1) - 1);
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // traverse the binary tree with BFS to count nodes
    int countNodesWithBFS(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int nums = 0;
        while (!q.empty()) {
            size_t sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                nums++;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return nums;
    }
};
}// namespace CompleteBinaryTreeNodes

TEST(Solution, countNodes) {
    CompleteBinaryTreeNodes::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 3, 4, 5, 6};
    TreeNode* root1 = BuildBinaryTree(nums1);
    EXPECT_EQ(sln.countNodes(root1), 6);
    EXPECT_EQ(sln.countNodesWithBFS(root1), 6);

    // case2
    std::vector<int> nums2;
    TreeNode* root2 = BuildBinaryTree(nums2);
    EXPECT_EQ(sln.countNodes(root2), 0);
    EXPECT_EQ(sln.countNodesWithBFS(root2), 0);

    // case3
    std::vector<int> nums3{1};
    TreeNode* root3 = BuildBinaryTree(nums3);
    EXPECT_EQ(sln.countNodes(root3), 1);
    EXPECT_EQ(sln.countNodesWithBFS(root3), 1);
}