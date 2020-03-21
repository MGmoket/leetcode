
#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p119 {

    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> res = { 1 };
            if (rowIndex <= 0) return res;

            for (int i = 1; i <= rowIndex; ++i) {
                vector<int> tmp = { 1 };
                res.swap(tmp);

                for (size_t i = 1; i < tmp.size(); ++i) {
                    res.push_back(tmp[i - 1] + tmp[i]);
                }
                res.push_back(1);
            }
            return res;
        }
    };
}


int test_p119_getRow() {
    using namespace p119;

    vector<int> res = Solution().getRow(4);
    println(res.begin(), res.end());

    return 0;
}
