/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;
namespace p114 {

    class Solution {
    public:
        void flatten(TreeNode* root) {
            while (root != nullptr) {
                if (root->left != nullptr) {
                    auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                    while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                    most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                    root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                    root->left = nullptr; // 将左孩子置为空
                }
                root = root->right; // 继续下一个节点
            }
            return;
        }
    };
}


int test_p114_flatten() {
    using namespace p114;

    vector<int> nums;
    TreeNode* root = NULL;

    nums = {1,2,5,3,4,0,6};
    root = makeBinaryTree(nums);
    Solution().flatten(root);

    return 0;
}
