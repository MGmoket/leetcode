#pragma once    

#include <iostream>
#include <vector>

struct ListNode {
int val;
ListNode* next;
ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

ListNode* makeList(const std::vector<int>& nums);
void printList(ListNode* l);

TreeNode* makeBinaryTree(const std::vector<int>& nums);
