/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p59 {
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res;
            for (int i = 0; i < n; ++i) {
                res.push_back(vector<int>(n, 0));
            }

            int l, r, s;
            l = 0;
            r = 0;
            s = n;
            int c = 0;
            while (true) {
                res[r][l] = ++c;

                for (int i = l+1; i < l + s; ++i) {
                    res[r][i] = ++c;
                }
                if (--s <= 0) break;
                l += s;

                for (int i = r+1; i <= r + s; ++i) {
                    res[i][l] = ++c;
                }
                r += s;

                for (int i = l - 1; i >= l - s; --i) {
                    res[r][i] = ++c;
                }
                l -= s--;
                if (s <= 0) break;
                
                for (int i = r - 1; i >= r-s; --i) {
                    res[i][l] = ++c;
                }
                r -= s;
                l++;
            }

            return res;
        }
    };

    class Solution2{
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> mat(n);
            for (int i = 0; i < n; ++i) {
                mat[i].resize(n);
            }

            int l, t, r, b;
            l = 0;
            t = 0;
            r = n-1;
            b = n - 1;
            
            int num = 1;
            int tar = n * n;
            while (num <= tar) {
                for (int i = l; i <= r; ++i) {
                    mat[t][i] = num++;
                }
                ++t;
                for (int i = t; i <= b; ++i) {
                    mat[i][r] = num++;
                }
                r--;
                for (int i = r; i >= l; --i) {
                    mat[b][i] = num++;
                }
                b--;
                for (int i = b; i >= t; --i) {
                    mat[i][l] = num++;
                }
                l++;
            }
            return mat;
        }

    };
}

int test_p59_generateMatrix() {
    using namespace p59;

    vector<vector<int>> result;

    result = Solution2().generateMatrix(6);
    for (auto v : result) {
        println(v.begin(), v.end());
    }

    return 0;
}
