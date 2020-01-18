/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "functions.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace p104 {
    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root == NULL) return 0;
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            return 1 + max(l, r);
        }
    };
}

int test_p104_maxDepth() {
    using namespace p104;

    TreeNode* root = NULL;
    vector<int> nums = { 3,9,20, 0, 0, 15,7 };
    root = makeBinaryTree(nums);

    cout << "maxDepth: " << Solution().maxDepth(root) << endl;

    return 0;
}