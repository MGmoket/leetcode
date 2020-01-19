/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "functions.h"
#include <vector>
#include <map>
using namespace std;

namespace p142 {
    class Solution {
    public:
        ListNode* detectCycle(ListNode* head) {
            map<ListNode*,int> nodes;
            ListNode* p = head;
            while (p != NULL) {
                if (nodes[p]++ > 0) return p;
                p = p->next;
            }
            return NULL;
        }
    };

    class Solution2 {
    public:
        ListNode* detectCycle(ListNode* head) {
            ListNode* p = meet(head);
            if (p == NULL) return NULL;
            ListNode* l = head;
            while (l != p) {
                l = l->next;
                p = p->next;
            }
            return l;
        }

    private:
        ListNode* meet(ListNode* head) {
            if (head == NULL) return NULL;

            ListNode* l1 = head;
            ListNode* l2 = head->next;
            while (l1 != NULL && l2 != NULL)
            {
                if (l1 == l2) return l1->next;

                l1 = l1->next;
                l2 = l2->next;
                if (l2 == NULL) return NULL;
                l2 = l2->next;
            }
            return NULL;
        }
    };
}


int test_p142_detectCycle() {
    using namespace p142;

    vector<int> nums;
    ListNode* head = NULL;

    nums = { 3,2,0,-4 };
    head = makeCycleList(nums, 1);
    cout << Solution2().detectCycle(head)->val << endl;

    nums = { 1,2 };
    head = makeCycleList(nums, 0);
    cout << Solution().detectCycle(head)->val << endl;

    nums = { 1 };
    head = makeCycleList(nums, -1);
    cout << Solution().detectCycle(head) << endl;

    return 0;
}
