//
// Created by 昭会 on 2024/7/4.
//

#ifndef LC_LINKEDLIST_H
#define LC_LINKEDLIST_H

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void print(ListNode *node) {
    while (node) {
        std::cout << node->val << std::endl;
        node = node->next;
    }
}

class Lc21{
public:
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) ;
    };
};
class Lc206 {
public:
    class Solution {
    public:
        ListNode *reverseList(ListNode *head);
    };
};


#endif //LC_LINKEDLIST_H
