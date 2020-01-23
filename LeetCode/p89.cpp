/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p89 {
    class Solution {
    public:
        vector<int> grayCode(int n) {
            if (n == 0) return {0};
            vector<int> gray = grayCode(n - 1);
            int append = 1 << (n - 1);
            vector<int> result(gray);
            for (auto it = gray.rbegin(); it != gray.rend(); ++it) {
                result.push_back(*it + append);
            }
            return result;
        }
    };

    class Solution2 {//更精彩的解法
    public:
        vector<int> grayCode(int n) {
            vector<int> res;
            for (int i = 0; i < pow(2, n); i++) {
                res.push_back((i >> 1) ^ i);
            }
            return res;
        }
    };
}

int test_p89_grayCode() {
    using namespace p89;

    vector<int> res;
    int n;

    n = 0;
    cout << "n=" << n << endl;
    res = Solution().grayCode(n);
    println(res.begin(), res.end());

    cout << endl;
    n = 1;
    cout << "n=" << n << endl;
    res = Solution().grayCode(n);
    println(res.begin(), res.end());
    cout << endl;

    n = 2;
    cout << "n=" << n << endl;
    res = Solution().grayCode(n);
    println(res.begin(), res.end());
    cout << endl;

    n = 3;
    cout << "n=" << n << endl;
    res = Solution().grayCode(n);
    println(res.begin(), res.end());
    cout << endl;

    return 0;
}

