//
// Created by shirleyz on 2024/7/5.
//

#include "TREE.h"

std::vector<int> res;
std::vector<int> TREE::Lc94::Solution::inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
    return res;
}
