//
// Created by 昭会 on 2024/7/4.
//

#include "LinkedList.h"
#include "map"

LinkedList::ListNode *LinkedList::Lc206::Solution::reverseList(ListNode *head) {
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

LinkedList::ListNode *LinkedList::Lc21::Solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto *currentNode = new ListNode();
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
        currentList2 = currentList2->next;
    }
    return head->next;
}

bool LinkedList::Lc141::Solution::hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slowNode = head;
    ListNode *fastNode = head->next;
    while (slowNode != fastNode) {
        if (fastNode == nullptr) {
            return false;
        }
        slowNode = slowNode->next;
        fastNode = fastNode->next;
        if (fastNode == nullptr) {
            return false;
        }
        fastNode = fastNode->next;
    }
    return true;
}

LinkedList::ListNode *LinkedList::Lc160::Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }
    ListNode *pA = headA;
    ListNode *pB = headB;
    while (pA != pB) {
        pA = pA->next;
        pB = pB->next;
        if (pA == pB) {
            return pA;
        }
        if (pA == nullptr) {
            pA = headB;
        }
        if (pB == nullptr) {
            pB = headA;
        }
    }
    return pA;
}
