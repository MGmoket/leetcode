/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include "functions.h"

using namespace std;

namespace p61 {
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (head == NULL || k == 0) return head;

            int count = 0;
            ListNode*last = countList(head, count);
            k = count - k % count;
            if (k == 0) return head;

            last->next = head;
            ListNode* p = head;
            while (k--) {
                last = p;
                p = p->next;
            }
            
            last->next = NULL;
            head = last->next;
            return p;
        }
    private:
        ListNode* countList(ListNode* head, int& count) {
            ListNode* p = head;
            ListNode* last = NULL;
            while (p) {
                last = p;
                p = p->next;
                ++count;
            }
            return last;
        }
    };
}

int test_p61_rotateRight() {
    using namespace p61;

    ListNode* head = makeList({1,2,3,4,5});
    head = Solution().rotateRight(head, 3);
    printList(head);
    cout << endl;

    return 0;
}

