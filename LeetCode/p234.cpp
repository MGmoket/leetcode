/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

namespace p234 {

}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = meet(head);
        ListNode* p2 = reverseList(mid);
        
        while (head != NULL && p2 != NULL) {
            if (head->val != p2->val) return false;
            head = head->next;
            p2 = p2->next;
        }
        
        return true;
    }

private:
    ListNode* meet(ListNode* head) {
        ListNode* low = head;
        ListNode* fast = head;

        while (low != NULL && fast != NULL) {
            low = low->next;
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
        }
        return low;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL)return head;
        ListNode* l = head;
        ListNode* p = head->next;
        
        l->next = NULL;
        while (p != NULL) {
            ListNode* t = p->next;
            p->next = l;
            l = p;
            p = t;
        }
        return l;
    }
};

int test_p234_isPalindrome() {
    using namespace p234;
    vector<int> nums;
    ListNode* head = NULL;

    nums = { 1,2 };
    head = makeList(nums);
    cout << Solution().isPalindrome(head) << endl;

    nums = { 1,2,2,1 };
    head = makeList(nums);
    cout << Solution().isPalindrome(head) << endl;
    
    nums = { 1,0,0 };
    head = makeList(nums);
    cout << Solution().isPalindrome(head) << endl;

    return 0;
}
