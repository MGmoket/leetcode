/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"


using namespace std;

namespace p54 {
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            if (matrix.size() == 0) return res;
            spiralOrder(matrix, -1, 0, matrix.front().size(), matrix.size(), true, res);
            return res;
        }

    private:
        void spiralOrder(vector<vector<int>>& matix, int x, int y, int w, int h, bool inc, vector<int>& res) {
            if ( w == 0 || h == 0 ) return;
            int stepin = 1;
            if (!inc) stepin = -1;

            int steps = w;
            
            while (steps-- > 0) {
                res.push_back(matix[y][x += stepin]);
            }

            steps = h - 1;
            while (steps-- > 0) {
                res.push_back(matix[y += stepin][x]);
            }

            spiralOrder(matix, x, y, w-1, h - 1, !inc, res);
        }
    };
}

int test_p54_spiralOrder() {
    using namespace p54;

    vector<int> nums;
    vector<vector<int>> matrix;
    
    matrix = { {1,2,3}, {4,5,6}, {7,8,9} };
    nums = Solution().spiralOrder(matrix);
    println(nums.begin(), nums.end());
    cout << endl;

    matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    nums = Solution().spiralOrder(matrix);
    println(nums.begin(), nums.end());
    cout << endl;

    return 0;
}
