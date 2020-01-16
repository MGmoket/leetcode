/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;
namespace p70 {
    class Solution {
    public:
        int climbStairs(int n) {
            if (n < 2) return 1;

            int p1 = 1;
            int p2 = 1;
            int p = 0;
            for (int i = 2; i <= n; ++i) {
                p = p1 + p2;
                p1 = p2;
                p2 = p;
            }
            return p;
        }
    };
}

int test_p70_climbStairs() {
    using namespace p70;

    int n;

    n = 2;
    cout << n << " stairs, ways to get there: " << Solution().climbStairs(n) << endl;

    n = 3;
    cout << n << " stairs, ways to get there: " << Solution().climbStairs(n) << endl;

    n = 4;
    cout << n << " stairs, ways to get there: " << Solution().climbStairs(n) << endl;

    return 0;
}
