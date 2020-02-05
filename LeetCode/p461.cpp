/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

using namespace std;

namespace p461 {
    class Solution {
    public:
        int hammingDistance(int x, int y) {
            return countOfOne(x ^ y);
        }

    private:
        int countOfOne(int x) {
            long cnt = 0;
            while (x) {
                ++cnt;
                x &= x - 1;
            }
            return cnt;
        }
    };
}

int test_p461_hammingDistance() {
    using namespace p461;

    int x, y;

    x = 1;
    y = 4;
    cout << Solution().hammingDistance(x, y) << endl;
    return 0;
}