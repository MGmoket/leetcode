
/**

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <iostream>
#include <stack>

using namespace std;
namespace p445 {


    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* l0 = new ListNode(0);

            std::stack<int> s1, s2;
            int val = add(l1, l2, l0, s1, s2);
            if (val) {
                ListNode* t = new ListNode(val);
                t->next = l0;
                l0 = t;
            }
            return l0;
        }
    private:

        int add(ListNode* l1, ListNode* l2, ListNode* l0, std::stack<int>& s1, std::stack<int>& s2) {
            int val = 0;
            if (l1->next != NULL && l2->next != NULL) {
                l0->next = new ListNode(0);
                s1.push(l1->val);
                s2.push(l2->val);
                val = add(l1->next, l2->next, l0->next, s1, s2);
            }
            else if (l1->next != NULL) {
                l0->next = new ListNode(0);
                s1.push(l1->val);
                val = add(l1->next, l2, l0->next, s1, s2);
            }
            else if (l2->next != NULL) {
                l0->next = new ListNode(0);
                s2.push(l2->val);
                val = add(l1, l2->next, l0->next, s1, s2);
            }
            else {
                s1.push(l1->val);
                s2.push(l2->val);
            }

            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }

            l0->val = val % 10;
            return val / 10;
        }
    };

    ListNode* createListNodes(long long num) {
        ListNode* l = new ListNode(num%10);
        num /= 10;

        while (num != 0)
        {
            ListNode* cur = new ListNode(num % 10);
            num /= 10;
            cur->next = l;
            l = cur;
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

int test_p445_addTwoNumbers() {
    using namespace p445;
    ListNode* l1 = createListNodes(7243);
    ListNode* l2 = createListNodes(564);
    printListNodes(l1);
    printListNodes(l2);
    ListNode* l3 = Solution().addTwoNumbers(l1, l2);
    printListNodes(l3);

    return 0;
}
