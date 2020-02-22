/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <stack>
#include "functions.h"
#include "myprint"

using namespace std;

namespace p94 {

    class Solution0 {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            inorderTraversal(root, res);
            return res;
        }

    private:
        void inorderTraversal(TreeNode* root, vector<int>& vals) {
            if (root == NULL) return;
            inorderTraversal(root->left, vals);
            vals.push_back(root->val);
            inorderTraversal(root->right, vals);
        }
    };

    class Solution1 {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> _stack;

            TreeNode* p = root;
            bool bStacked = false;
            while (p != NULL) {
                if (p->left != NULL && !bStacked) {
                    _stack.push(p);
                    p = p->left;
                    continue;
                }
                bStacked = false;
                res.push_back(p->val);
                if (p->right != NULL) {
                    p = p->right;
                    continue;
                }

                if (_stack.size() == 0) break;
                bStacked = true;
                p = _stack.top();
                _stack.pop();
            }
            return res;
        }
    };


    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> _stack;

            TreeNode* p = root;
            while (p != NULL || !_stack.empty()) {
                while (p != NULL) {
                    _stack.push(p);
                    p = p->left;
                }

                p = _stack.top();
                _stack.pop();
                res.push_back(p->val);
                p = p->right;
            }
            return res;
        }
    };


}

int test_p94_inorderTraversal() {
    using namespace p94;

    vector<int> res;
    vector<int> nums;
    TreeNode* root = NULL;


    nums = {1,0,2,3};
    root = makeBinaryTree(nums);

    res = Solution().inorderTraversal(root);
    println(res.begin(), res.end());

    return 0;
}