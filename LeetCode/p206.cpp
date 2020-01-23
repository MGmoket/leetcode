/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
namespace p206 {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr = head;

            while (curr != NULL) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            return prev;
        }
    };
}

int test_p206_reverseList() {
    using namespace p206;
    vector<int> nums;
    ListNode* head = NULL;
    ListNode* nl = NULL;

    nums = { 1,2,3 };
    head = makeList(nums);
    nl = Solution().reverseList(head);
    printList(nl);

    return 0;
}
