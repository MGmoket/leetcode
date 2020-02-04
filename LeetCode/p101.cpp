
#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

namespace p101 {

    class Solution2 {
    public:
        bool isSymmetric(TreeNode* root) {
            vector<int> lv, rv;
            lscan(root, lv);
            rscan(root, rv);

            for (int i = 0; i < lv.size(); ++i) {
                if (lv[i] != rv[i]) return false;
            }
            return true;
        }
    private:
        void lscan(TreeNode* root, vector<int>& vals) {
            if (root == NULL) {
                vals.push_back(INT_MIN);
                return;
            }
            vals.push_back(root->val);
            rscan(root->left, vals);
            rscan(root->right, vals);
        }

        void rscan(TreeNode* root, vector<int>& vals) {
            if (root == NULL) {
                vals.push_back(INT_MIN);
                return;
            }
            vals.push_back(root->val);
            lscan(root->right, vals);
            lscan(root->left, vals);
        }
    };


    class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root == NULL) return true;
            
            return isSame(root->left, root->right);
        }

    private:
        bool isSame(TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            return isSame(p->left, q->right) && isSame(p->right, q->left);
        }
    };
}    

int test_p101_isSymmetric() {
    using namespace p101;

    vector<int> nums;
    TreeNode* root;

    nums = { 1,2,2,3,4,4,3 };
    root = makeBinaryTree(nums);
    cout << Solution().isSymmetric(root) << endl;

    return 0;
}
