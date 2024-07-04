#include <iostream>
#include "Easy/LinkedList.h"

int main() {
    // test Lc206
    Lc206::Solution solution;
    ListNode *head = new ListNode(0);
    int length = 5;
    ListNode *currentNode;
    currentNode = head;
    for (int i = 1; i < length; ++i) {
        ListNode *nextNode = new ListNode(i);
        currentNode->next = nextNode;
        currentNode = nextNode;
    }
    std::cout << "original list:" << std::endl;
    currentNode = head;
    while (currentNode) {
        std::cout << currentNode->val << std::endl;
        currentNode = currentNode->next;
    }
    ListNode *newHead = solution.reverseList(head);
    std::cout << "after reversing:" << std::endl;
    currentNode = newHead;
    while (currentNode) {
        std::cout << currentNode->val << std::endl;
        currentNode = currentNode->next;
    }

    return 0;
}
