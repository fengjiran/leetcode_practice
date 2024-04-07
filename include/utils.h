//
// Created by richard on 12/23/23.
//

#ifndef LEETCODE_PRACTICE_UTILS_H
#define LEETCODE_PRACTICE_UTILS_H

#include "gtest/gtest.h"
#include <cmath>
#include <fstream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <memory>

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

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class BinaryHeap {
    std::vector<int> pq{0};
    int len{0};
    void swim(int k) {
        while (k > 1 && pq[k] > pq[k / 2]) {
            std::swap(pq[k], pq[k / 2]);
            k = k / 2;
        }
    }

    void sink(int k) {
        while (2 * k <= len) {
            int j = 2 * k;
            if (j < len && pq[j + 1] > pq[j]) {
                j++;
            }
            if (pq[k] >= pq[j]) {
                break;
            }
            std::swap(pq[k], pq[j]);
            k = j;
        }
    }

public:
    void insert(int v) {
        pq.push_back(v);
        len++;
        swim(len);
    }

    int deleteMax() {
        int max = pq[1];
        std::swap(pq[1], pq[len]);
        pq[len] = 0;
        len--;
        sink(1);
        return max;
    }

    int size() const {
        return len;
    }

    bool empty() const {
        return len == 0;
    }
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
