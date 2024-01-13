//
// Created by richard on 12/23/23.
//

#ifndef LEETCODE_PRACTICE_UTILS_H
#define LEETCODE_PRACTICE_UTILS_H

#include "gtest/gtest.h"
//#include <filesystem>
#include <cmath>
#include <fstream>
#include <queue>
#include <set>
#include <unordered_set>

#define null INT32_MIN

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class UnionFind {
public:
    explicit UnionFind(int n) : count(n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionNodes(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }

        parent[rootP] = rootQ;
        count--;
    }

    bool isConnected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getCount() {
        return count;
    }

private:
    int count;
    std::vector<int> parent;
};

bool Compare2DVector(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2);

bool Compare2DString(std::vector<std::string>& str1, std::vector<std::string>& str2);

bool isPalindrome(const std::string& s, int left, int right);

// construct binary tree from level order
// ref:https://developer.aliyun.com/article/1217826
TreeNode* BuildBinaryTree(const std::vector<int>& nums);

void PrintBinaryTreeLevelOrder(TreeNode* root);

std::optional<std::string> getFileDir(const std::string& filePath);

std::optional<std::vector<std::vector<char>>> get2DCharFromFile(const char* file_path);

#endif//LEETCODE_PRACTICE_UTILS_H
