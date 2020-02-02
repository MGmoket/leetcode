/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>

#include "functions.h"
using namespace std;

namespace p543 {
    class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int ans = 1;
            depth(root, ans);
            return ans - 1;
        }
    private:
        int depth(TreeNode* node, int& ans) {
            if (node == NULL) return 0;

            int L = depth(node->left, ans);
            int R = depth(node->right, ans);

            ans = max(ans, L + R + 1);
            return max(L, R) + 1;
        }
    };
}
