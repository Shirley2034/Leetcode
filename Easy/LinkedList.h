//
// Created by 昭会 on 2024/7/4.
//

#ifndef LC_LINKEDLIST_H
#define LC_LINKEDLIST_H

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
};


#endif //LC_LINKEDLIST_H
