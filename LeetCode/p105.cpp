/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"

using namespace std;

namespace p105 {

    class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if (preorder.empty() || inorder.empty()) return NULL;
            int val = preorder.front();

            auto it = find(inorder.begin(), inorder.end(), val);
            if (it == inorder.end()) return NULL;
            preorder.erase(preorder.begin());

            TreeNode* root = new TreeNode(val);

            vector<int> left = vector<int>(inorder.begin(), it);
            vector<int> right = vector<int>(++it, inorder.end());

            root->left = buildTree(preorder, left);
            root->right = buildTree(preorder, right);

            return root;
        }
    };

}


int test_p105_buildTree() {
    using namespace p105;
    vector<int> nums;

    vector<int> preorder;
    vector<int> inorder;
    TreeNode* root;

    preorder = { 3,9,20,15,7 };
    inorder = { 9,3,15,20,7 };

    root = Solution().buildTree(preorder, inorder);
    
    return 0;
}
