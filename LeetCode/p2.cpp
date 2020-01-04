/**
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <iostream>
using namespace std;
namespace p2 {


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l0 = new ListNode(0);
        ListNode* iter = l0;
        int val = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val += l2->val;
                l2 = l2->next;
            }

            iter = iter->next = new ListNode(val % 10);
            val /= 10;
        }
        if (val) iter->next = new ListNode(val % 10);
        iter = l0->next;
        l0->next = nullptr;
        delete l0;
        return iter;
    }

};

ListNode *createListNodes(long long num) {
    ListNode* l = new ListNode(num % 10);
    ListNode* cur = l;
    num /= 10;

    while (num != 0)
    {
        cur->next = new ListNode(num % 10);
        num /= 10;
        cur = cur->next;
    }

    return l;
}

void printListNodes(ListNode* l) {
    ListNode* idx = l;
    while (idx != nullptr)
    {
        if (idx != l) {
            cout << " -> ";
        }
        cout << idx->val;
        idx = idx->next;
    }
    cout << endl;
}

}

int test_p2_addTwoNumbers() {
    using namespace p2;
    ListNode* l1 = createListNodes(342);
    ListNode* l2 = createListNodes(465);
    printListNodes(l1);
    printListNodes(l2);
    ListNode* l3 = Solution().addTwoNumbers(l1, l2);
    printListNodes(l3);

    return 0;
}
