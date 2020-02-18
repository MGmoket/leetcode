/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>

#include "myprint"

using namespace std;

namespace p64 {
    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            //动态规划DP，可以直接在原数组上修改
            for (int i = 0; i < grid.size(); i++) {//遍历行
                for (int j = 0; j < grid[0].size(); j++) {//遍历列
                    if (i == 0 && j == 0) continue;//注意cpp和python语法的不同，不能用i==j==0条件来判断
                    else if (i == 0) grid[i][j] += grid[i][j - 1];//对于第一行边界元素特殊处理，只能从左边的元素得到当前的最短路径和
                    else if (j == 0) grid[i][j] += grid[i - 1][j];//对于第一列边界元素特殊处理，只能从上面的元素得到当前的最短路径和
                    else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);//一般元素取其上面或左边元素的最小值
                }
            }
            return grid[grid.size() - 1][grid[0].size() - 1];
        }
    };
}

int test_p64_minPathSum() {
    using namespace p64;
    vector<vector<int>> grid;

    grid = { {1,3,1},{1,5,1},{4,2,1} };

    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
