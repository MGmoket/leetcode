/*

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p344 {
    class Solution {
    public:
        void reverseString(vector<char>& s) {
            if (s.size() == 0)return;
            size_t j = s.size() - 1;
            size_t i = 0;
            while (i < j) {
                swap(s[i++], s[j--]);
            }
        }
    };
}

int test_p344_reverseString() {
    using namespace p344;
    vector<char> str = {'h','e','l','l','o'};
    Solution().reverseString(str);
    println(str.begin(), str.end());

    return 0;
}

