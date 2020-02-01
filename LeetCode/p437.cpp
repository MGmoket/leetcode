/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "functions.h"
using namespace std;

namespace p437 {
    class Solution2 {
    public:
        int pathSum(TreeNode* root, int sum) {
            int* array = new int[1000];
            memset(array, 0, sizeof(int) * 1000);
            return pathSum(root, sum, array, 0);
        }
    private:
        int pathSum(TreeNode* root, int sum, int array[], int p) {
            if (root == NULL) return 0;

            int tmp = root->val;
            int n = (tmp == sum ? 1 : 0);
            for (int i = p - 1; i >= 0; --i) {
                tmp += array[i];
                if (tmp == sum) n++;
            }
            array[p] = root->val;

            int n1 = pathSum(root->left, sum, array, p + 1);
            int n2 = pathSum(root->right, sum, array, p + 1);

            return n + n1 + n2;
        }
    };
}
class Solution {
    int pathCnt;
public:
    int pathSum(TreeNode* root, int sum) {
        pathCnt = 0;
        pathsum(root, sum);
        return pathCnt;
    }
private:
    vector<int> pathsum(TreeNode* root, int sum) {
        vector<int> ret;
        if (root == NULL) return ret;

        int val = root->val;
        ret.push_back(root->val);
        vector<int> lv = pathsum(root->left, sum);
        vector<int> rv = pathsum(root->right, sum);
        if (!lv.empty()) {
            for (int l : lv) {
                ret.push_back(val+l);
            }
        }
        if (!rv.empty()) {
            for (int r : rv) {
                ret.push_back(val+r);
            }
        }

        /*for (int l : lv) {
            for (int r : rv) {
                ret.push_back(val + l + r);
            }
        }*/

        for (int v : ret) {
            if (v == sum) {
                pathCnt++;
            }
        }

        return ret;
    }
};

int test_p437_pathSum() {
    using namespace p437;
    vector<int> nums;
    TreeNode* root = NULL;
    int sum = 0;


    nums = { 10,5,-3,3,2,0,11,3,-2,0,1 };
    sum = 8;
    root = makeBinaryTree(nums);

    cout << Solution2().pathSum(root, sum) << endl;
    
    return 0;
}

