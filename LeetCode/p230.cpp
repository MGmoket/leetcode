/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#include "functions.h"

using namespace std;
namespace p230 {
    class Solution {
    private:
        priority_queue<int, vector<int>, less<int>> q;
    public:
        int kthSmallest(TreeNode* root, int k) {
            haveKthSmallest(root, k);
            return q.top();
        }

    private:
        bool haveKthSmallest(TreeNode* root, int k) {
            if (root->left != NULL && haveKthSmallest(root->left, k)) return true;
            q.push(root->val);
            if (q.size() == k) return true;

            if (root->right != NULL && haveKthSmallest(root->right, k)) return true;

            return q.size() == k;
        }
    };
}

int test_p230_kthSmallest() {
    using namespace p230;
    vector<int> nums;
    int k = 0;
    TreeNode* root = NULL;

    nums = {3,1,4,0,2};
    k = 3;
    root = makeBinaryTree(nums);
    cout << Solution().kthSmallest(root, k) << endl;
    return 0;
}

