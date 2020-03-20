/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p66 {
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int p = 1;
            for (int i = digits.size() - 1; i >= 0; --i) {
                int v = digits[i] + p;
                digits[i] = v % 10;
                p = v / 10;
                if (p == 0) break;
            }
            if (p != 0) digits.insert(digits.begin(), p);
            return digits;
        }
    };
}


int test_p66_plusOne() {
    using namespace p66;

    vector<int> digits,res;
    digits = { 1,2,3 };
    res = Solution().plusOne(digits);
    println(res.begin(), res.end());

    digits = { 4,3,2,1 };
    res = Solution().plusOne(digits);
    println(res.begin(), res.end());

    digits = { 9,9 };
    res = Solution().plusOne(digits);
    println(res.begin(), res.end());
 
    return 0;
}
