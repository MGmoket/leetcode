/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include "functions.h"

using namespace std;
namespace p19 {

    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;

            ListNode* p = dummyHead;
            ListNode* q = dummyHead;
            for (int i = 0; i < n + 1; i++) {
                q = q->next;
            }

            while (q) {
                p = p->next;
                q = q->next;
            }

            ListNode* delNode = p->next;
            p->next = delNode->next;
            delete delNode;

            ListNode* retNode = dummyHead->next;
            delete dummyHead;

            return retNode;

        }
    };

}

int test_p19_removeNthFromEnd() {
    using namespace p19;
    vector<int> nums;
    ListNode* head = NULL;
    int n = 0;

    head = makeList(nums);
    n = 2;
    head = Solution().removeNthFromEnd(head, n);
    printList(head);

    return 0;
}
