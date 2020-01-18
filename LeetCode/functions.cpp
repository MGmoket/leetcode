#include "functions.h"
#include <vector>
#include <iostream>

using namespace std;

ListNode* makeList(const vector<int>& nums) {
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

void fullChildren(const std::vector<int>& nums, int start, const vector<TreeNode*>& children) {

    vector<TreeNode*> newChildren;
    for (auto child : children) {
        if (start >= nums.size()) return;
        if (child == NULL) continue;

        int l = nums[start++];
        if (l != 0) child->left = new TreeNode(l);
        if (start >= nums.size()) return;

        int r = nums[start++];
        if (r != 0) child->right = new TreeNode(r);
        newChildren.push_back(child->left);
        newChildren.push_back(child->right);
    }

    fullChildren(nums, start, newChildren);
    
}

TreeNode* makeBinaryTree(const std::vector<int>& nums) {
    if (nums.empty()) return NULL;

    TreeNode* root = new TreeNode(nums[0]);

    fullChildren(nums, 1, { root });
    return root;
}

