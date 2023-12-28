//
// Created by richard on 12/23/23.
//
#include "utils.h"

namespace BinaryTreePaths {
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        return res;
    }

    std::vector<std::string> binaryTreePaths1(TreeNode* root) {
        traverse(root, "");
        return res;
    }

    void backtrack(TreeNode* root) {
        track.push_back(root->val);
        if (!root->left && !root->right) {
            std::string path;
            for (int i = 0; i < track.size() - 1; i++) {
                path += std::to_string(track[i]);
                path += "->";
            }
            path += std::to_string(track.back());
            res.push_back(path);
            return;
        }

        if (root->left) {
            backtrack(root->left);
            track.pop_back();
        }

        if (root->right) {
            backtrack(root->right);
            track.pop_back();
        }
    }

    // preorder
    void traverse(TreeNode* root, std::string path) {
        if (!root) {
            return;
        }

        path += std::to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        path += "->";

        traverse(root->left, path);
        traverse(root->right, path);
    }

    void resetMems() {
        track.clear();
        res.clear();
    }

    std::vector<int> track;
    std::vector<std::string> res;
};
}// namespace BinaryTreePaths

TEST(Solution, binaryTreePaths) {
    BinaryTreePaths::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 3, null, 5};
    std::vector<std::string> ans1{"1->2->5", "1->3"};
    TreeNode* root1 = BuildBinaryTree(nums1);
    std::vector<std::string> res1 = sln.binaryTreePaths(root1);
    EXPECT_TRUE(Compare2DString(res1, ans1));

    sln.resetMems();

    // case2
    std::vector<int> nums2{1};
    std::vector<std::string> ans2{"1"};
    TreeNode* root2 = BuildBinaryTree(nums2);
    std::vector<std::string> res2 = sln.binaryTreePaths(root2);
    EXPECT_TRUE(Compare2DString(res2, ans2));

    sln.resetMems();

    // case3
    std::vector<int> nums3{1, 2, 3, 4, 5, 6, 7, 8, null, 10, 11, null, 13, null, 15};
    std::vector<std::string> ans3{"1->2->4->8", "1->2->5->10", "1->2->5->11", "1->3->6->13", "1->3->7->15"};
    TreeNode* root3 = BuildBinaryTree(nums3);
    std::vector<std::string> res3 = sln.binaryTreePaths(root3);
    EXPECT_TRUE(Compare2DString(res3, ans3));
}

TEST(Solution, binaryTreePaths1) {
    BinaryTreePaths::Solution sln;

    // case1
    std::vector<int> nums1{1, 2, 3, null, 5};
    std::vector<std::string> ans1{"1->2->5", "1->3"};
    TreeNode* root1 = BuildBinaryTree(nums1);
    std::vector<std::string> res1 = sln.binaryTreePaths1(root1);
    EXPECT_TRUE(Compare2DString(res1, ans1));

    sln.resetMems();

    // case2
    std::vector<int> nums2{1};
    std::vector<std::string> ans2{"1"};
    TreeNode* root2 = BuildBinaryTree(nums2);
    std::vector<std::string> res2 = sln.binaryTreePaths1(root2);
    EXPECT_TRUE(Compare2DString(res2, ans2));

    sln.resetMems();

    // case3
    std::vector<int> nums3{1, 2, 3, 4, 5, 6, 7, 8, null, 10, 11, null, 13, null, 15};
    std::vector<std::string> ans3{"1->2->4->8", "1->2->5->10", "1->2->5->11", "1->3->6->13", "1->3->7->15"};
    TreeNode* root3 = BuildBinaryTree(nums3);
    std::vector<std::string> res3 = sln.binaryTreePaths1(root3);
    EXPECT_TRUE(Compare2DString(res3, ans3));
}

TEST(Solution, TestBinaryTreeConstructAndPrint) {
    GTEST_SKIP();
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, null, 10, 11, null, 13, null, 15};
    TreeNode* root = BuildBinaryTree(nums);
    PrintBinaryTreeLevelOrder(root);
}
