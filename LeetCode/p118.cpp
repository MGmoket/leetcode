

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p118 {
    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res;
            if (numRows <= 0) return res;
            res.push_back({ 1 });
            for (int i = 2; i <= numRows; ++i) {
                vector<int> it;
                vector<int>& p = res.back();
                it.push_back(1);
                for (int k = 1; k < p.size(); ++k) {
                    it.push_back(p[k - 1] + p[k]);
                }
                it.push_back(1);
                res.push_back(it);
            }

            return res;
        }
    };
}


int test_p118_generate() {
    using namespace p118;
    vector<vector<int>> res;

    res = Solution().generate(5);
    for (auto it : res) {
        println(it.begin(), it.end());
    }


    return 0;
}
