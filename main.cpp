#include <iostream>

#include "Easy/Array.h"
#include "Easy/LinkedList.h"
#include "Easy/STACK.h"
#include "Easy/STRING.h"
#include "Easy/TREE.h"
#include "Easy/MATH.h"
#include "Medium/MATRIX.h"
#include "Medium/STRUCT.h"

int main() {
    // test Lc206
    // LinkedList::Lc206::Test::test1();
    // LinkedList::Lc21::Test::test1();
    // STACK::Lc121::Test::test1();
    // STACK::Lc122::Test::test1();
    //     Array::Lc88::Test::test1();
    //    LinkedList::Lc141::Test::test1();
    //    STRING::Lc415::Test::test1();
    //    TREE::Lc94::Test::test1();
    //    TREE::Lc104::Test::test1();
    //    Array::Lc704::Test::test1();
    //    MATH::Solution solution;
    //    std::cout<<"result is "<< solution.mySqrt(2147395599)<<std::endl;
    //    TREE::Lc101::Solution solution;
    //    solution.test4();
    //    TREE::Lc543::Solution solution;
    //    solution.test1();
    //    STRING::Lc14::Solution solution;
    //    solution.test1();
    //    LinkedList linkedList;
    //    LinkedList::ListNode *node = linkedList.case2();
    //    linkedList.printList(node);
    //    std::cout<<"--------------"<<std::endl;
    //    LinkedList::Lc234::Solution solution;
    //    if (solution.isPalindrome(node)) {
    //        std::cout << "it is palindrome" << std::endl;
    //    } else {
    //        std::cout << "it is not palindrome" << std::endl;
    //    }
    //    Array::Lc34::Solution solution;
    //    std::vector<int> case1 = {2,2};
    //    std::vector<int> res = solution.searchRange(case1, 2);
    // TREE::Lc108::Solution solution;
    // TREE::Lc94::Solution solution2;
    // std::vector<int> nums = {-10, -3, 0, 5, 9};
    // TREE::TreeNode *root = solution.sortedArrayToBST(nums);
    // STRING::Lc3::Solution solution;
    // std::string s = "abdbcde";
    // std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
    // std::vector<std::vector<char> > grid = {
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '1', '0'},
    //     {'0', '0', '1', '0', '1'}
    // };
    // STRUCT::Lc200 solution;
    // std::cout << solution.numIslands(grid) << std::endl;
    // std::vector<std::vector<int> > m = {{1}, {5}};
    // MATRIX::Lc54::Solution solution;
    // std::vector<int> res = solution.spiralOrder(m);
    // for (const int &num: res) {
    //     std::cout << num << ",";
    // }
    // std::cout << std::endl;
    // TREE::Cases cases;
    // TREE::Lc226::Solution solution;
    // TREE::TreeNode *root = solution.invertTree(cases.case4());
    // std::string s = "101023";
    // STRING::Lc93::Solution solution;
    // std::vector<std::string> res = solution.restoreIpAddresses(s);
    // for(std::string &ele:res) {
    //     std::cout<<ele<<std::endl;
    // }
//    std::string text1 = "spqrs";
//    std::string text2 = "sqrp";
//    STRING::Lc1143::Solution solution;
//    std::cout << solution.longestCommonSubsequence(text1, text2) << std::endl;
    LinkedList::Lc82::Solution solution;
    std::vector<int> case1 = {1, 2,2};
    LinkedList::ListNode *head = LinkedList::generateLinkedListByVec(case1);
    LinkedList::ListNode *newHead = solution.deleteDuplicates(head);
    LinkedList::printList(newHead);
    return 0;
}
