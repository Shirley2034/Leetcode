//
// Created by shirleyz on 2024/7/5.
//

#include "TREE.h"
#include "queue"
#include "set"

std::vector<int> res;

std::vector<int> TREE::Lc94::Solution::inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
    return res;
}

bool TREE::Lc101::Solution::check(TREE::TreeNode *p, TREE::TreeNode *q) {
    if (!p && !q) { return true; }
    if (!p || !q) { return false; }
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool TREE::Lc101::Solution::isSymmetric(TREE::TreeNode *root) {
    return check(root->left, root->right);
}

int TREE::Lc104::Solution::maxDepth(TREE::TreeNode *root) {
    return currentDepth(root, 0);
}

int TREE::Lc110::Solution::height(TREE::TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = height(root->right);
    if (rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    } else {
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool TREE::Lc110::Solution::isBalanced(TREE::TreeNode *root) {
    return height(root) != -1;
}


bool TREE::Lc112::Solution::hasPathSum(TREE::TreeNode *root, int targetSum) {
    std::queue<std::pair<TreeNode *, int>> Q;
    Q.emplace(std::make_pair(root, root->val));
    std::set<int> pathSumSet;
    while (!Q.empty()) {
        size_t s = Q.size();
        while (s > 0) {
            std::pair<TreeNode *, int> parent = Q.front();
            Q.pop();
            if (parent.first->left) {
                Q.emplace(std::make_pair(parent.first->left, parent.second + parent.first->left->val));
            } else {
                pathSumSet.insert(parent.first->val);
            }
            if (parent.first->right) {
                Q.emplace(std::make_pair(parent.first->right, parent.second + parent.first->right->val));
            } else {
                pathSumSet.insert(parent.first->val);
            }
            s--;
        }
    }
    return pathSumSet.find(targetSum) != pathSumSet.end();
}

int TREE::Lc543::Solution::maxDepth(TREE::TreeNode *root, int &dia) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = maxDepth(root->left, dia);
        int rightDepth = maxDepth(root->right, dia);
        dia = std::max(dia, leftDepth + rightDepth);
        return std::max(leftDepth, rightDepth) + 1;
    }
}

int TREE::Lc543::Solution::diameterOfBinaryTree(TREE::TreeNode *root) {
    int res = 0;
    int ans = maxDepth(root->left, res) + maxDepth(root->right, res);
    return std::max(ans, res);
}