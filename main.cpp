#include <iostream>
#include "Easy/LinkedList.h"

int main() {
    // test Lc206
    LinkedList::Lc206::Solution solution;
    auto *head = new LinkedList::ListNode(0);
    LinkedList::ListNode *currentNode=head;
    for (int i = 1; i < 5; ++i) {
        auto *nextNode = new LinkedList::ListNode(i);
        currentNode->next = nextNode;
        currentNode = nextNode;
    }
    std::cout << "original list:" << std::endl;
    LinkedList::printList(head);
    LinkedList::ListNode *newHead = solution.reverseList(head);
    std::cout << "after reversing:" << std::endl;
    LinkedList::printList(newHead);

    return 0;
}
