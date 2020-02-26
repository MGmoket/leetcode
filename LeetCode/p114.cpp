/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
namespace p114 {

    class Solution {
    public:
        void flatten(TreeNode* root) {
            while (root != nullptr) {
                if (root->left != nullptr) {
                    auto most_right = root->left; // �����������Ϊ��, ��ô�����ҵ������������ҽڵ�
                    while (most_right->right != nullptr) most_right = most_right->right; // �����ҽڵ�
                    most_right->right = root->right; // Ȼ�󽫸����Һ��ӷŵ����ҽڵ����������
                    root->right = root->left; // ��ʱ������Һ��ӿ����ͷ�, ����������ӷŵ��Һ�����
                    root->left = nullptr; // ��������Ϊ��
                }
                root = root->right; // ������һ���ڵ�
            }
            return;
        }
    };
}


int test_p114_flatten() {
    using namespace p114;

    vector<int> nums;
    TreeNode* root = NULL;

    nums = {1,2,5,3,4,0,6};
    root = makeBinaryTree(nums);
    Solution().flatten(root);

    return 0;
}
