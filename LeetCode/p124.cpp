/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"

using namespace std;
namespace p124 {
    class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int val = INT_MIN;
            maxPathSum(root, val);
            return val;
        }
    private:
        int maxPathSum(TreeNode* root, int& val) {
            if (root == NULL) return 0;

            int left = maxPathSum(root->left, val);
            int right = maxPathSum(root->right, val);
            int lmr = root->val + max(0, left) + max(0, right);
            int ret = root->val + max(0, max(left, right));
            val = max(val, max(lmr, ret));
            return ret;
        }
    };
}

int test_p124_maxPathSum() {
    using namespace p124;

    TreeNode* root = NULL;
    vector<int> nums;

    nums = { 1,2,3 };
    root = makeBinaryTree(nums);
    cout << Solution().maxPathSum(root) << endl;

    nums = { -10,9,20,0,0,15,7 };
    root = makeBinaryTree(nums);
    cout << Solution().maxPathSum(root) << endl;

    return 0;
}