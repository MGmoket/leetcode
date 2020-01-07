/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-two-sorted-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include <vector>

using namespace std;

namespace p21 {

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

            ListNode* l = new ListNode(0);
            ListNode* p = l;

            while (l1 != NULL && l2 != NULL) {
                if (l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                }
                else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            if (l1 == NULL) p->next = l2;
            if (l2 == NULL) p->next = l1;

            p = l->next;
            delete l;
            
            return p;
        }
    };

    class Solution2 { // �ð汾�����ۣ���Ȼ����ջ����ķ���
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;
            if (l1->val < l2->val)
            {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else
            {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    };

    ListNode* makeList(vector<int> nums) {
        if (nums.size() == 0) return NULL;
        ListNode* l = new ListNode(nums.front());
        ListNode* p = l;
        for (size_t i = 1; i < nums.size(); ++i) {
            p->next = new ListNode(nums[i]);
            p = p->next;
        }

        return l;
    }

    void printList(ListNode* l) {
        ListNode* p = l;
        while (p != NULL) {
            if (p != l) {
                cout << "->";
            }
            cout << p->val;
            p = p->next;
        }
    }

}

int test_p21_mergeTowLists() {
    using namespace p21;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    l1 = makeList({1,2,4});
    l2 = makeList({ 1,3,4 });
    printList(Solution().mergeTwoLists(l1, l2));
    cout << endl;

    return 0;
}
