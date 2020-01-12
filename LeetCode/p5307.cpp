/*

Given an integer n. No-Zero integer is a positive integer which doesn't contain any 0 in its decimal representation.

Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. If there are many valid solutions you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in their decimal representation.
Example 2:

Input: n = 11
Output: [2,9]
Example 3:

Input: n = 10000
Output: [1,9999]
Example 4:

Input: n = 69
Output: [1,68]
Example 5:

Input: n = 1010
Output: [11,999]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;



namespace p5307 {
    class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            for (int i = 1; i < n; ++i) {
                int p = n - 1;
                if (!isContainZero(i) && !isContainZero(p)) {
                    return { i,n - i };
                }
            }
            return {};
        }
    private:
        bool isContainZero(int n) {
            while (n != 0) {
                if (n % 10 == 0) return true;
                n /= 10;
            }
            return false;
        }
    };
}

int test_p5307_getNoZeroIntegers() {
    using namespace p5307;
    vector<int> res;

/*    res = Solution().getNoZeroIntegers(2);
    println(res.begin(),res.end());
    cout << endl;
*/
    res = Solution().getNoZeroIntegers(11);
    println(res.begin(), res.end());
    cout << endl;

    return 0;
}
