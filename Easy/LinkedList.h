//
// Created by 昭会 on 2024/7/4.
//

#ifndef LC_LINKEDLIST_H
#define LC_LINKEDLIST_H

#include <vector>
#include "iostream"

class LinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {
        }

        explicit ListNode(int x) : val(x), next(nullptr) {
        }

        ListNode(int x, ListNode *next) : val(x), next(next) {
        }
    };

    static void printList(ListNode *node) {
        ListNode *currentNode = node;
        while (currentNode) {
            std::cout << currentNode->val << std::endl;
            currentNode = currentNode->next;
        }
    }

    static ListNode *case1() {
        auto *head = new ListNode(0);
        ListNode *currentNode = head;
        for (int i = 1; i < 5; ++i) {
            auto *nextNode = new ListNode(i);
            currentNode->next = nextNode;
            currentNode = nextNode;
        }
        return head;
    }

    static ListNode *case2() {
        auto *head = new ListNode(-6);
        ListNode *currentNode = head;
        for (int i = -2; i < 5; ++i) {
            auto *nextNode = new ListNode(2 * i);
            currentNode->next = nextNode;
            currentNode = nextNode;
        }
        return head;
    }

    static ListNode *generateLinkedListByVec(std::vector<int> &inputVec) {
        if (inputVec.empty()) {
            return nullptr;
        }
        ListNode *head = new ListNode(inputVec[0]);
        ListNode *currentNode = head;
        for (int i = 1; i < inputVec.size(); i++) {
            ListNode *nextNode = new ListNode(inputVec[i]);
            currentNode->next = nextNode;
            currentNode = nextNode;
        }
        return head;
    }

    static ListNode *hasCycle() {
        ListNode *head = case2();
        head->next = head;
        // ListNode *node1 = head;
        // for (int i = 0; i < 3; i++) {
        //     node1 = node1->next;
        // }
        // ListNode *node2 = head;
        // for (int i = 0; i < 5; i++) {
        //     node2 = node2->next;
        // }
        // node2->next = node1;
        return head;
    }

    class Lc21 {
    public:
        class Solution {
        public:
            ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                ListNode *list1 = case1();
                ListNode *list2 = case2();
                std::cout << "list1:" << std::endl;
                printList(list1);
                std::cout << "list2:" << std::endl;
                printList(list2);
                ListNode *res = solution.mergeTwoLists(list1, list2);
                std::cout << "merge list1 and list2:" << std::endl;
                printList(res);
            }
        };
    };

    class Lc23 {
    public:
        class Solution {
            void minHeapify(std::vector<ListNode *> &lists, int start, int end) {
                int parent = start;
                int child = 2 * parent + 1;
                while (child <= end) {
                    //找到左右孩子中值最小的那个
                    if (child + 1 <= end && lists[child]->val > lists[child + 1]->val) {
                        child++;
                    }
                    //如果父节点的值比孩子节点小，那么结束比较
                    if (lists[parent]->val < lists[child]->val) {
                        return;
                    }
                    //否则交换父节点和孩子节点的值
                    ListNode *node = lists[parent];
                    lists[parent] = lists[child];
                    lists[child] = node;
                    parent = child;
                    child = 2 * parent + 1;
                }
            }

        public:
            ListNode *mergeKLists(std::vector<ListNode *> &lists) {
                std::vector<ListNode *> currentList;
                //确保没有空节点
                for (ListNode *node: lists) {
                    if (node != nullptr) {
                        currentList.push_back(node);
                    }
                }
                int len = currentList.size();
                if (len == 0) {
                    return nullptr;
                }
                //建立小根堆
                for (int i = len / 2 - 1; i >= 0; i--) {
                    minHeapify(currentList, i, len - 1);
                }
                //创建一个哑节点，连接头节点
                auto *prevNode = new ListNode();
                //此时currentList[0]的值最小
                int end = len - 1;
                ListNode *head = currentList[0];
                prevNode->next = head;
                while (end >= 0) {
                    if (head->next != nullptr) {
                        currentList[0] = head->next;
                        //维护小根堆
                        minHeapify(currentList, 0, end);
                        //更新头节点
                        head->next = currentList[0];
                        head = head->next;
                    } else {
                        //交换头尾元素
                        ListNode *node = currentList[0];
                        currentList[0] = currentList[end];
                        currentList[end] = node;
                        end--;
                        if (end >= 0) {
                            //维护小根堆
                            minHeapify(currentList, 0, end);
                            head->next = currentList[0];
                            head = head->next;
                        }
                    }
                }
                return prevNode->next;
            }
        };
    };

    class Lc82 {
    public:
        class Solution {
        public:
            ListNode *deleteDuplicates(ListNode *head) {
                auto *newHead = new ListNode();
                ListNode *res = newHead;
                while (head != nullptr) {
                    bool isDuplicate = false;
                    int nodeVal = head->val;
                    while (head->next != nullptr && head->next->val == nodeVal) {
                        head = head->next;
                        isDuplicate = true;
                    }
                    //如果是重复节点，需要删除；如果不是重复节点，则添加
                    if (!isDuplicate) {
                        newHead->next = head;
                        newHead = newHead->next;
                    }
                    head = head->next;
                }
                newHead->next = nullptr;
                return res->next;
            }
        };
    };


    class Lc140 {
    public:
        class Solution {
        public:
            ListNode *trainingPlan(ListNode *head, int cnt);
        };
    };

    class Lc206 {
    public:
        class Solution {
        public:
            ListNode *reverseList(ListNode *head);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                ListNode *head = case1();
                std::cout << "original list:" << std::endl;
                printList(head);
                ListNode *newHead = solution.reverseList(head);
                std::cout << "after reversing:" << std::endl;
                printList(newHead);
            }
        };
    };

    class Lc141 {
    public:
        class Solution {
        public:
            bool hasCycle(ListNode *head);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                ListNode *head = hasCycle();
                if (solution.hasCycle(head)) {
                    std::cout << "This linked list has cycle." << std::endl;
                } else {
                    std::cout << "This linked list does not have cycle." << std::endl;
                }
            }
        };
    };

    class Lc160 {
    public:
        class Solution {
        public:
            ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
        };
    };

    class Lc234 {
    public:
        class Solution {
            ListNode *reverseLinkedList(ListNode *head) {
                ListNode *nextNode = nullptr;
                ListNode *currentNode = head;
                while (currentNode != nullptr) {
                    ListNode *temp = currentNode->next;
                    currentNode->next = nextNode;
                    nextNode = currentNode;
                    currentNode = temp;
                }
                return nextNode;
            }

        public:
            bool isPalindrome(ListNode *head) {
                ListNode *anotherHead = reverseLinkedList(head);
                while (head != nullptr) {
                    if (head->val == anotherHead->val) {
                        head = head->next;
                        anotherHead = anotherHead->next;
                    } else {
                        return false;
                    }
                }
                return true;
            }
        };

        class Test {
        public:
            void test1() {
                std::vector<int> inputVec = {1, 1, 2, 1};
                Solution solution;
                ListNode *head = generateLinkedListByVec(inputVec);
                printList(head);
            }
        };
    };
};


#endif //LC_LINKEDLIST_H
