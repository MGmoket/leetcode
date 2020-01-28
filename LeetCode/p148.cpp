/*

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
namespace p148 {
    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head->next == NULL) return head;

            ListNode* mid = midNode(head);
            ListNode* next = mid->next;
            mid->next = NULL;

            head = sortList(head);
            next = sortList(next);
            return mergeLists(head, next);
        }
    private:
        ListNode* mergeLists(ListNode* l1, ListNode* l2) {
            ListNode* l = NULL;
            if (l1->val < l2->val) {
                l = l1;
                l1 = l1->next;
            }
            else {
                l = l2;
                l2 = l2->next;
            }

            ListNode* p = l;
            while (l1 != NULL && l2 != NULL) {
                if (l1->val > l2->val) {
                    p->next = l2;
                    l2 = l2->next;
                }
                else {
                    p->next = l1;
                    l1 = l1->next;
                }
                p = p->next;
            }
            if (l1 != NULL) p->next = l1;
            if (l2 != NULL) p->next = l2;
            return l;
        }

        ListNode* midNode(ListNode* head) {
            ListNode* low = head;
            ListNode* fast = head;
            while (fast != NULL) {

                fast = fast->next;
                if (fast == NULL) break;
                fast = fast->next;
                if (fast == NULL) break;

                low = low->next;
            }
            return low;
        }
    };
}



int test_p148_sortList() {
    using namespace p148;
    vector<int> nums;
    ListNode* head = NULL;

    nums = { 4,2,1,3 };
    head = makeList(nums);
    head = Solution().sortList(head);
    printList(head);
    cout << endl;

    nums = { -1,5,3,4,0 };
    head = makeList(nums);
    head = Solution().sortList(head);
    printList(head);
    cout << endl;
    return 0;
}
