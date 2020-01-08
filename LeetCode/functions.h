#pragma once    

#include <iostream>
#include <vector>

struct ListNode {
int val;
ListNode* next;
ListNode(int x) : val(x), next(NULL) {}
};

ListNode* makeList(std::vector<int> nums);
void printList(ListNode* l);

