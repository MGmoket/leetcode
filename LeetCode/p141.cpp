/*
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "functions.h"
#include <iostream>

using namespace std;

namespace p141 {
    class Solution {
    public:
        bool hasCycle(ListNode* head) {
            if (head == NULL) return false;
            ListNode* l1 = head;
            ListNode* l2 = head->next;
            while (l1 != NULL && l2 != NULL) {
                if (l1 == l2) return true;
                l1 = l1->next;
                l2 = l2->next;
                if (l2 != NULL) l2 = l2->next;
            }
            return false;
        }
    };
}

int test_p141_hasCycle() {

    using namespace p141;


    vector<int> nums;
    ListNode* head = NULL;
    
    nums = { 3,2,0,-4 };
    head = makeCycleList(nums, 1);
    cout << Solution().hasCycle(head) << endl;

    nums = { 1,2 };
    head = makeCycleList(nums, 0);
    cout << Solution().hasCycle(head) << endl;

    nums = {1};
    head = makeCycleList(nums, -1);
    cout << Solution().hasCycle(head) << endl;


    return 0;
}
