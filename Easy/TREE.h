//
// Created by shirleyz on 2024/7/5.
//

#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "vector"

class TREE {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {
        }

        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }

        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
        }
    };


    class Lc94 {
    public:
        class Solution {
        public:
            std::vector<int> inorderTraversal(TreeNode *root);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                auto *root = new TreeNode(4);
                auto *left = new TreeNode(2);
                auto *left1 = new TreeNode(1);
                auto *right1 = new TreeNode(3);
                auto *right = new TreeNode(5);
                left->left=left1;
                left->right = right1;
                root->left = left;
                root->right = right;
                std::cout << "root is " << root->val << " ";
                std::cout << "left child is " << root->left->val << " ";
                std::cout << "right child is " << root->right->val << " ";
                std::vector<int> res = solution.inorderTraversal(root);
                std::cout << "inorder traversal is ";
                for (const int &num: res) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                delete root;
                delete left;
                delete right;
                delete left1;
                delete right1;
            }
        };
    };
};


#endif //TREE_H
