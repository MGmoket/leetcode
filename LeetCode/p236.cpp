/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"

using namespace std;

namespace p236 {
    class Solution {
        TreeNode* ans;
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            ans = NULL;
            find(root, p, q);
            return ans;
        }
    private:
        bool find(TreeNode* root, TreeNode* p, TreeNode*q) {
            if (root == NULL) return false;
            int left = find(root->left, p, q) ? 1 : 0;
            int right = find(root->right, p, q) ? 1 : 0;
            int mid = (root == p || root == q) ? 1 : 0;
            int sum = left + right + mid;
            if (sum >= 2) {
                ans = root;
            }
            return sum > 0;
        }
    };
}    

int test_p236_lowestCommonAncestor() {
    using namespace p236;

    TreeNode* root, *node;
    vector<int> nums;

    nums = { 3,5,1,6,2,-1,8,0,0,7,4 };
    root = makeBinaryTree(nums);
    node = Solution().lowestCommonAncestor(root, root->left, root->right);
    

    return 0;
}