/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include "functions.h"

using namespace std;

namespace p23 {

    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            size_t cnt = lists.size();
            if (cnt == 0) return NULL;
            if (cnt == 1) return lists.front();

            lists[lists.size() - 2] = mergeTwoLists(lists[lists.size() - 2], lists[lists.size() - 1]);
            lists.resize(lists.size() - 1);
            return mergeKLists(lists);
        }

    private:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;

            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    };

    class Solution2 {// 更优思路
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if (lists.size() == 0) return NULL;
            return mergeKLists(lists, 0, lists.size()-1);
        }

    private:
        ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
            if (start == end) return lists[start];
            int mid = (start + end) >> 1;

            ListNode* l1 = mergeKLists(lists, start, mid);
            ListNode* l2 = mergeKLists(lists, mid + 1, end);
            return mergeTwoLists(l1, l2);
        }

        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;

            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    };

}

int test_p23_mergeKLists() {

    using namespace p23;

    vector<ListNode*>lists;
    ListNode* l = NULL;
    
    lists = { makeList({ 1,4,5 }), makeList({ 1,3,4 }), makeList({ 2,6 }) };
    l = Solution2().mergeKLists(lists);
    printList(l);

    return 0;
}

