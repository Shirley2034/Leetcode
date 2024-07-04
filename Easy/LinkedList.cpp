//
// Created by 昭会 on 2024/7/4.
//

#include "LinkedList.h"

ListNode *Lc206::Solution::reverseList(ListNode *head) {
    ListNode *currentNode = nullptr;
    ListNode *nextNode = head;
    while (nextNode) {
        ListNode *node = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        currentNode->next = node;
    }
    return currentNode;
}

ListNode *Lc21::Solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *currentNode = nullptr;
    ListNode *currentList1 = list1;
    ListNode *currentList2 = list2;
    ListNode *head = currentNode;
    while (currentList1 && currentList2) {
        if (currentList1->val > currentList2->val) {
            currentNode->next = currentList2;
            currentList2 = currentList2->next;
        } else {
            currentNode->next = currentList1;
            currentList1 = currentList1->next;
        }
        currentNode = currentNode->next;
    }
    while (currentList1) {
        currentNode->next = currentList1;
        currentList1 = currentList1->next;
        currentNode = currentNode->next;
    }
    while (currentList2) {
        currentNode->next = currentList2;
        currentNode = currentList2;
        currentList2->next = currentList2;
    }
    return head;
}
