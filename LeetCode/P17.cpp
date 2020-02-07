/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>
#include "myprint"

using namespace std;

namespace p17 {
    class Solution {
        vector<string> res;
    public:
        vector<string> letterCombinations(string digits) {

            if (digits.empty()) return res;

            string leeterMap[] = {
                " ",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
            };
            findCombination(digits, 0, "", leeterMap);
            return res;
        }
    private:
        void findCombination(string digits, int index, string s, string leeterMap[]) {
            if (index == digits.length()) {
                res.push_back(s);
                return;
            }

            char c = digits.at(index);
            string letters = leeterMap[c - '0'];
            for (int i = 0; i < letters.length(); ++i) {
                string t(s);
                t.push_back(letters[i]);
                findCombination(digits, index + 1, t, leeterMap);
            }
        }
    };
}


int test_p17_letterCombinations() {
    using namespace p17;

    string digits;
    vector<string> res;

    digits = "23";
    res = Solution().letterCombinations(digits);
    println(res.begin(), res.end());

    return 0;
}
