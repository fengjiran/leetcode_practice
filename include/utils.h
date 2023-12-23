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

bool Compare2DVector(std::vector<std::vector<int>> &nums1, std::vector<std::vector<int>> &nums2) {
    if (nums1.size() != nums2.size()) {
        return false;
    }

    std::stable_sort(nums1.begin(), nums1.end());
    std::stable_sort(nums2.begin(), nums2.end());

    for (int i = 0; i < nums1.size(); i++) {
        bool isEqual = std::equal(nums1[i].begin(), nums1[i].end(),
                                  nums2[i].begin(), nums2[i].end());
        if (!isEqual) {
            return false;
        }
    }
    return true;
}

bool Compare2DString(std::vector<std::string> &str1, std::vector<std::string> &str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    std::stable_sort(str1.begin(), str2.end());
    std::stable_sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

// construct binary tree from level order
TreeNode *BuildBinaryTree(const std::vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }

    auto *root = new TreeNode(nums[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode *cur = q.front();
        q.pop();
        if (nums[i] != null) {
            cur->left = new TreeNode(nums[i]);
            q.push(cur->left);
        }
        i++;

        if (nums[i] != null) {
            cur->right = new TreeNode(nums[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

#endif //LEETCODE_PRACTICE_UTILS_H
