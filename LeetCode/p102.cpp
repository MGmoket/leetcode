/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "myprint"
#include "functions.h"

using namespace std;

namespace p102 {
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            levelOrder(root, 1, res);
            return res;
        }

    private:
        void levelOrder(TreeNode* root, size_t level, vector<vector<int>>& res) {
            if (root == NULL) return;

            if (res.size() < level) {
                res.push_back({});
            }
            res[level - 1].push_back(root->val);
            levelOrder(root->left, level + 1, res);
            levelOrder(root->right, level + 1, res);
        }
    };
}


int test_p102_levelOrder() {
    using namespace p102;
    vector<int> nums;
    TreeNode* root = NULL;
    vector<vector<int>> res;

    nums = { 3,9,20,0,0,15,7 };
    root = makeBinaryTree(nums);
    res = Solution().levelOrder(root);
    for (auto it : res) {
        println(it.begin(), it.end());
    }


    return 0;
}

