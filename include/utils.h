//
// Created by richard on 12/23/23.
//

#ifndef LEETCODE_PRACTICE_UTILS_H
#define LEETCODE_PRACTICE_UTILS_H

#include <queue>
#include "gtest/gtest.h"

#define null INT32_MIN

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool Compare2DVector(std::vector<std::vector<int>> &nums1, std::vector<std::vector<int>> &nums2);

bool Compare2DString(std::vector<std::string> &str1, std::vector<std::string> &str2);

// construct binary tree from level order
// ref:https://developer.aliyun.com/article/1217826
TreeNode *BuildBinaryTree(const std::vector<int> &nums);

void PrintBinaryTreeLevelOrder(TreeNode *root);

#endif //LEETCODE_PRACTICE_UTILS_H
