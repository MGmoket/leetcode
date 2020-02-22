/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>

using namespace std;

namespace p95 {

    class Solution {
    public:
        int numTrees(int n) {
            vector<int> rcd(n + 1);
            rcd[0] = 1;
            rcd[1] = 1;

            return numTrees(n, rcd);
        }

    private:
        long numTrees(int n, vector<int>& rcd) {
            if (rcd[n] != 0) return rcd[n];
            long nums = 0;

            for (int i = 1; i <= n; ++i) {
                nums += numTrees(i - 1, rcd) * numTrees(n - i, rcd);
            }
            return rcd[n] = nums;
        }
    };

}


int test_p95_numTrees() {
    using namespace p95;

    cout << Solution().numTrees(15) << endl;

    return 0;
}
