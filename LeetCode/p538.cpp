/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

namespace p538 {
    class Solution {
    public:
        TreeNode* convertBST(TreeNode* root) {
            int sum = 0;
            return convertBST(root, sum);
        }

    private:
        TreeNode* convertBST(TreeNode* root, int& sum) {
            if (root == NULL) return root;
            convertBST(root->right, sum);
            sum += root->val;
            root->val = sum;
            convertBST(root->left, sum);
            return root;
        }
    };
}



int test_p538_convertBST() {
    using namespace p538;
    
    return 0;
}
