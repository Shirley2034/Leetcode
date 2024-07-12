//
// Created by shirleyz on 2024/7/5.
//

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <map>
#include <queue>

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

    class Cases {
    public:
        TreeNode *case1() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(2);
            auto *left1 = new TreeNode(1);
            auto *right1 = new TreeNode(3);
            auto *right = new TreeNode(5);
            left->left = left1;
            left->right = right1;
            root->left = left;
            root->right = right;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   /  \\" << std::endl;
            std::cout << "  " << root->left->val << "    " << root->right->val << std::endl;
            std::cout << " / \\" << std::endl;
            std::cout << left->left->val << "   " << left->right->val << std::endl;
            return root;
        }

        TreeNode *case2() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(2);
            auto *left1 = new TreeNode(1);
            auto *right1 = new TreeNode(3);
            auto *right = new TreeNode(2);
            left->left = left1;
            left->right = right1;
            root->left = left;
            root->right = right;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   /  \\" << std::endl;
            std::cout << "  " << root->left->val << "    " << root->right->val << std::endl;
            std::cout << " / \\" << std::endl;
            std::cout << left->left->val << "   " << left->right->val << std::endl;
            return root;
        }

        TreeNode *case3() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(2);
            auto *left1 = new TreeNode(1);
            auto *right1 = new TreeNode(1);
            auto *right = new TreeNode(2);
            left->left = left1;
            right->right = right1;
            root->left = left;
            root->right = right;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   /  \\" << std::endl;
            std::cout << "  " << root->left->val << "    " << root->right->val << std::endl;
            std::cout << " /      \\" << std::endl;
            std::cout << left->left->val << "        " << right1->val << std::endl;
            return root;
        }

        TreeNode *case4() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(2);
            auto *left1 = new TreeNode(6);
            auto *right1 = new TreeNode(8);
            auto *left2 = new TreeNode(10);
            auto *right2 = new TreeNode(11);
            auto *right = new TreeNode(3);
            left->left = left1;
            left->right = right1;
            right->left = right2;
            right->right = left2;
            root->left = left;
            root->right = right;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   /  \\" << std::endl;
            std::cout << "  " << root->left->val << "    " << root->right->val << std::endl;
            std::cout << " / \\   / \\" << std::endl;
            std::cout << left->left->val << "   " << left->right->val << "  " << right->left->val << "  "
                    << right->right->val
                    << std::endl;
            return root;
        }

        TreeNode *case5() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(2);
            auto *left1 = new TreeNode(1);
            auto *right1 = new TreeNode(3);
            auto *right = new TreeNode(2);
            left->left = left1;
            left->right = right1;
            root->left = left;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   / " << std::endl;
            std::cout << "  " << root->left->val << std::endl;
            std::cout << " / \\" << std::endl;
            std::cout << left->left->val << "   " << left->right->val
                    << std::endl;
            return root;
        }

        TreeNode *case6() {
            auto *root = new TreeNode(4);
            auto *left = new TreeNode(-7);
            auto *right = new TreeNode(-3);
            root->left = left;
            root->right = right;
            auto *left1 = new TreeNode(-9);
            auto *right1 = new TreeNode(3);
            right->left = left1;
            left = new TreeNode(1);
            left1->left = left;
            right->right = right1;
            right = new TreeNode(2);
            right1->right = right;
            left1 = new TreeNode(3);
            right1 = new TreeNode(5);
            left->right = left1;
            right->left = right1;
            std::cout << "    " << root->val << "  " << std::endl;
            std::cout << "   /  \\" << std::endl;
            std::cout << " " << root->left->val << "   " << root->right->val << std::endl;
            std::cout << "       / \\" << std::endl;
            std::cout << "     " << root->right->left->val << "   " << root->right->right->val << std::endl;
            std::cout << "      /     \\" << std::endl;
            std::cout << "     " << root->right->left->left->val << "       " << root->right->right->right->val
                    << std::endl;
            std::cout << "      \\     /" << std::endl;
            std::cout << "       " << root->right->left->left->right->val << "   "
                    << root->right->right->right->left->val
                    << std::endl;
            return root;
        }
    };

    class Lc50 {
    public:
        class Solution {
            int rootPathSum(TreeNode *root, long long targetSum) {
                // 计算从根节点root出发的所有路径总和
                int pathSum = 0;
                if (root == nullptr) {
                    return pathSum;
                }
                std::queue<TreeNode *> Q;
                std::queue<long long> targetQ;
                Q.push(root);
                targetQ.push(targetSum);
                while (!Q.empty()) {
                    int s = Q.size();
                    while (s > 0) {
                        TreeNode *parent = Q.front();
                        long long target = targetQ.front();
                        Q.pop();
                        targetQ.pop();
                        if (parent->val == target) {
                            pathSum++;
                        }
                        if (parent->left != nullptr) {
                            Q.push(parent->left);
                            targetQ.push(target - parent->val);
                        }
                        if (parent->right != nullptr) {
                            Q.push(parent->right);
                            targetQ.push(target - parent->val);
                        }
                        s--;
                    }
                }
                return pathSum;
            }

        public:
            int pathSum(TreeNode *root, int targetSum) {
                int sum = 0;
                if (root == nullptr) {
                    return sum;
                }
                std::queue<TreeNode *> Q;
                Q.push(root);
                // 层序遍历所有节点
                while (!Q.empty()) {
                    int s = Q.size();
                    while (s > 0) {
                        TreeNode *parent = Q.front();
                        Q.pop();
                        // 计算以parent为起点的路径总和
                        sum += rootPathSum(parent, targetSum);
                        if (parent->left != nullptr) {
                            Q.push(parent->left);
                        }
                        if (parent->right != nullptr) {
                            Q.push(parent->right);
                        }
                        s--;
                    }
                }
                return sum;
            }
        };

        class Solution2 {
            int dfs(TreeNode *node, long long curr, std::map<long long, int> hashMap,
                    int &targetSum) {
                if (node == nullptr) {
                    return 0;
                }
                curr += node->val;
                int pathSum = 0;
                auto it = hashMap.find(curr - targetSum);
                // 判断从节点p_{k+1}到节点node的路径是否为目标路径
                if (it != hashMap.end()) {
                    pathSum = it->second;
                }
                // 判断从根节点root到node的路径是否为目标路径
                if (curr == targetSum) {
                    pathSum++;
                }
                it = hashMap.find(curr);
                if (it == hashMap.end()) {
                    hashMap[curr] = 1;
                } else {
                    hashMap[curr] += 1;
                }
                if (node->left != nullptr) {
                    pathSum += dfs(node->left, curr, hashMap, targetSum);
                }
                if (node->right != nullptr) {
                    pathSum += dfs(node->right, curr, hashMap, targetSum);
                }
                return pathSum;
            }

        public:
            int pathSum(TreeNode *root, int targetSum) {
                if (root == nullptr) {
                    return 0;
                }
                long long curr = root->val;
                int pathSum = 0;
                if (curr == targetSum) {
                    pathSum++;
                }
                std::map<long long, int> hashMap;
                hashMap[curr] = 1;
                pathSum += dfs(root->left, curr, hashMap, targetSum);
                pathSum += dfs(root->right, curr, hashMap, targetSum);
                return pathSum;
            }
        };
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
                Cases cases;
                Solution solution;
                TreeNode *root = cases.case1();
                std::vector<int> res = solution.inorderTraversal(root);
                std::cout << "inorder traversal is ";
                for (const int &num: res) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
        };
    };

    class Lc101 {
    public:
        class Solution {
        public:
            bool check(TreeNode *p, TreeNode *q);

            bool isSymmetric(TreeNode *root);

            void test4() {
                Cases cases;
                TreeNode *root = cases.case4();
                if (isSymmetric(root)) {
                    std::cout << "It is symmetric" << std::endl;
                } else {
                    std::cout << "It is not symmetric" << std::endl;
                }
            }


            void test2() {
                Cases cases;
                TreeNode *root = cases.case2();
                if (isSymmetric(root)) {
                    std::cout << "It is symmetric" << std::endl;
                } else {
                    std::cout << "It is not symmetric" << std::endl;
                }
            }

            void test3() {
                Cases cases;
                TreeNode *root = cases.case3();
                if (isSymmetric(root)) {
                    std::cout << "It is symmetric" << std::endl;
                } else {
                    std::cout << "It is not symmetric" << std::endl;
                }
            }
        };
    };

    class Lc104 {
    public:
        class Solution {
        private:
            int currentDepth(TreeNode *root, int depth) {
                if (root) {
                    depth++;
                    return std::max(currentDepth(root->left, depth), currentDepth(root->right, depth));
                }
                return depth;
            }

        public:
            int maxDepth(TreeNode *root);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                Cases cases;
                TreeNode *root = cases.case1();
                int res = solution.maxDepth(root);
                std::cout << "the max depth is " << res << std::endl;
            }
        };
    };

    class Lc108 {
    public:
        class Solution {
        public:
            TreeNode *sortedArrayToBST(std::vector<int> &nums) {
                int left = 0;
                int right = nums.size() - 1;
                TreeNode *root = new TreeNode(nums[(left + right) / 2]);
                std::queue<TreeNode *> Q;
                std::queue<int> leftQ;
                std::queue<int> rightQ;
                Q.emplace(root);
                leftQ.emplace(left);
                rightQ.emplace(right);
                while (!Q.empty()) {
                    size_t s = Q.size();
                    while (s > 0) {
                        TreeNode *node = Q.front();
                        Q.pop();
                        left = leftQ.front();
                        right = rightQ.front();
                        leftQ.pop();
                        rightQ.pop();
                        int mid = (left + right) / 2;
                        if (left <= mid - 1) {
                            TreeNode *leftNode = new TreeNode(nums[(left + mid - 1) / 2]);
                            node->left = leftNode;
                            Q.emplace(leftNode);
                            leftQ.emplace(left);
                            rightQ.emplace(mid - 1);
                        }
                        if (mid + 1 <= right) {
                            TreeNode *rightNode = new TreeNode(nums[(mid + 1 + right) / 2]);
                            leftQ.emplace(mid + 1);
                            rightQ.emplace(right);
                            node->right = rightNode;
                            Q.emplace(rightNode);
                        }
                        s--;
                    }
                }
                return root;
            }
        };
    };

    class Lc110 {
    public:
        class Solution {
        private:
            int height(TreeNode *root);

        public:
            bool isBalanced(TreeNode *root);
        };
    };

    class Lc112 {
    public:
        class Solution {
            int pathSum(TreeNode *root, int sum);

        public:
            bool hasPathSum(TreeNode *root, int targetSum);
        };
    };

    class Lc226 {
    public:
        class Solution {
        public:
            TreeNode *invertTree(TreeNode *root) {
                if (root == nullptr) {
                    return nullptr;
                }
                TreeNode *node = root->left;
                root->left = invertTree(root->right);
                root->right = invertTree(node);
                return root;
            }
        };
    };

    class Lc543 {
    public:
        class Solution {
        private:
            int maxDepth(TreeNode *root, int &dia);

        public:
            int diameterOfBinaryTree(TreeNode *root);

            void test1() {
                Cases cases;
                TreeNode *root = cases.case6();
                std::cout << "The diameter is " << diameterOfBinaryTree(root) << std::endl;
            }
        };
    };
};


#endif //TREE_H
