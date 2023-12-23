//
// Created by richard on 12/23/23.
//
#include "utils.h"

namespace BinaryTreePaths {
    class Solution {
    public:
        std::vector<std::string> binaryTreePaths(TreeNode *root) {
            backtrack(root);
            return res;
        }

        std::vector<std::string> binaryTreePaths1(TreeNode *root) {
            traverse(root, "");
            return res;
        }

        void backtrack(TreeNode *root) {
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
        void traverse(TreeNode *root, std::string path) {
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
}

//TEST(Solution, binaryTreePaths) {
//    BinaryTreePaths::Solution sln;
//
//    // case1
//    std::vector<int> case1{0, null};
//
//}
//
//TEST(Solution, binaryTreePaths1) {
//    //
//}

TEST(Solution, TestBinaryTreeConstructAndPrint) {
    GTEST_SKIP();
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, null, 10, 11, null, 13, null, 15};
    TreeNode *root = BuildBinaryTree(nums);
    PrintBinaryTreeLevelOrder(root);
}
