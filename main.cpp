#include <iostream>
#include "Easy/LinkedList.h"

int main() {
    // test Lc206
    LinkedList::Lc206::Solution solution206;
    LinkedList::ListNode *head = new LinkedList::ListNode(0);
    LinkedList::ListNode *currentNode;
    currentNode = head;
    for (int i = 1; i < 5; ++i) {
        LinkedList::ListNode *nextNode = new LinkedList::ListNode(i);
        currentNode->next = nextNode;
        currentNode = nextNode;
    }
    std::cout << "original list:" << std::endl;
    LinkedList::printList(head);
    LinkedList::ListNode *newHead = solution206.reverseList(head);
    std::cout << "after reversing:" << std::endl;
    LinkedList::printList(newHead);

    LinkedList::Lc21::Solution solution21;
    LinkedList::ListNode *egList1 = head;
    LinkedList::ListNode *egList2 = new LinkedList::ListNode(-1);
    currentNode = egList2;
    for (int i = 0; i < 8; i++) {
        LinkedList::ListNode *nextNode = new LinkedList::ListNode(i + 2);
        currentNode->next = nextNode;
        currentNode = nextNode;
    }
    std::cout << "original list1:" << std::endl;
    LinkedList::printList(egList1);
    std::cout << "original list2:" << std::endl;
    LinkedList::printList(egList2);
    LinkedList::ListNode *res = solution21.mergeTwoLists(egList1, egList2);
    std::cout << "merge list1 and list2:" << std::endl;
    LinkedList::printList(res);



    return 0;
}
