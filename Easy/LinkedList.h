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

    ListNode * test1() {

    }

    class Lc21 {
    public:
        class Solution {
        public:
            ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);
        };
    };

    class Lc206 {
    public:
        class Solution {
        public:
            ListNode *reverseList(ListNode *head);
        };
    };
};


#endif //LC_LINKEDLIST_H
