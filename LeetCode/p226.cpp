/*

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can��t invert a binary tree on a whiteboard so f*** off.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/invert-binary-tree
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include "functions.h"
using namespace std;

namespace p226 {
    class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) {
            if (root == NULL) return NULL;
            TreeNode* l = invertTree(root->left);
            TreeNode* r = invertTree(root->right);
            
            root->left = r;
            root->right = l;
            return root;
        }
    };
}
