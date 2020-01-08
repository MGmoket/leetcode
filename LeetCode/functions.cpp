#include "functions.h"
#include <vector>
#include <iostream>

using namespace std;

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
