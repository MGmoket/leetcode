/*
Write a program to find the node at which the intersection of two singly linked lists begins.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <set>
#include "functions.h"
#include "myprint"

using namespace std;

namespace p160 {
    class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            ListNode* pa = headA;
            ListNode* pb = headB;

            while (pa != NULL || pb != NULL) {
                if (pa == pb) {
                    return pa;
                }
                pa = ((pa == NULL) ? headB : pa->next);
                pb = ((pb == NULL) ? headA : pb->next);
            }

            return NULL;
        }
    };
}

int test_p160_getIntersectionNode() {
    using namespace p160;

    vector<int> numA, numB;
    ListNode* headA, * headB, *head;

    numA = { 4,1,8,4,5 };
    numB = { 5,0,1,8,4,5 };
    headA = makeList(numA);
    headB = makeList(numB);

    head = Solution().getIntersectionNode(headA, headB);
    printList(head);

    return 0;
}
