/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

namespace p98 {

    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, LONG_MIN, LONG_MAX);
        }

    private:
        bool isValidBST(TreeNode* root, long low, long hight) {
            if (root == NULL) return true;
            long num = root->val;

            if (num <= low || num >= hight) return false;
            return isValidBST(root->left, low, num) && isValidBST(root->right, num, hight);
        }
    };
}

int test_p98_isValidBST() {
    using namespace p98;

    TreeNode* root = NULL;
    vector<int> nums;

    nums = {2,1,3};
    root = makeBinaryTree(nums);
    cout << Solution().isValidBST(root) << endl;

    nums = {5,1,4,0,0,3,6};
    root = makeBinaryTree(nums);
    cout << Solution().isValidBST(root) << endl;

    nums = { 10,5,15,0,0,6,20 };
    root = makeBinaryTree(nums);
    cout << Solution().isValidBST(root) << endl;

    nums = { 2147483647 };
    root = makeBinaryTree(nums);
    cout << Solution().isValidBST(root) << endl;

    nums = { 1,1 };
    root = makeBinaryTree(nums);
    cout << Solution().isValidBST(root) << endl;

    return 0;
}

