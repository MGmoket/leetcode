/*


*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;


namespace p1310 {

    class Solution {
    public:
        vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            vector<int> ixor = vector<int>(queries.size());

            for (size_t i = 0; i < queries.size(); ++i) {
                vector<int>& it = queries[i];
                ixor[i] = xorRange(arr, it[0], it[1]);//  arr[it[0]] ^ arr[it[1]];
            }

            return ixor;
        }

    private:
        int xorRange(vector<int>& arr, size_t k, size_t j) {
            int ret = arr[k];
            for (size_t i = k + 1; i <= j; ++i) {
                ret ^= arr[i];
            }

            return ret;
        }
    };

    /*
    作者：LeetCode
        链接：https ://leetcode-cn.com/problems/xor-queries-of-a-subarray/solution/zi-shu-zu-yi-huo-cha-xun-by-leetcode/
    来源：力扣（LeetCode）
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    class Solution2 {
    public:
        vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
            int n = arr.size();
            vector<int> pre(n + 1);
            for (int i = 1; i <= n; ++i) {
                pre[i] = pre[i - 1] ^ arr[i - 1];
            }
            vector<int> ans;
            for (const auto& query : queries) {
                ans.push_back(pre[query[0]] ^ pre[query[1] + 1]);
            }
            return ans;
        }
    };

}

int test_p1310_xorQueries() {
    using namespace p1310;

    vector<int> arr;
    vector<vector<int>> queries;
    vector<int> ixor;

    arr = { 1,3,4,8 };
    queries = { {0,1},{1,2},{0,3},{3,3} };
    ixor = Solution().xorQueries(arr, queries);
    println(ixor.begin(), ixor.end());

    return 0;
}
