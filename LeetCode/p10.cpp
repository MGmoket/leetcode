/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace p10 {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            
            while (true) {
                if (p.empty() && s.empty()) return true;

                size_t pos = p.find('*');
                if (pos < p.length()) {
                    ++pos;
                }
                if (pos == 0) {
                    if (s.empty()) return true;
                    return false;
                }
                int len = matchLength(s, p.substr(0, pos));
                if (len == -1) return false;

                if (pos == std::string::npos) {
                    if (len != s.length()) return false;
                    return true;
                }

                p = p.substr(pos);
                s = s.substr(len);
            }
            return true;
        }
    private:
        /*
            p中至多有一个*
        */
        int matchLength(string s, string p) {
            if (p.empty()) return 0;

            string part;
            if (p.back() != '*') {
                part = p;
                p.clear();
            }
            else {
                part = p.substr(0, p.length() - 2);
                p = p.substr(p.length() - 2);
            }

            for (size_t i = 0; i < part.length(); ++i) {
                if (part[i] == '.') continue;
                if (part[i] != s[i]) return -1;
            }
            int len = part.length();

            if (p.length() == 2) {
                if (p[0] == '.') return s.length();
                while (len < s.length()) {
                    if (s[len] != p[0]) break;
                    ++len;
                }
            }
            return len;
        }

    private:
        string formatPattern(string p) {
            size_t pos = 0;
            while (pos < p.length()) {
                size_t t = p.find('*', pos);
                if (t == std::string::npos) break;
                ++t;
                size_t n = t;
                while (n < p.length()) {
                    if (p[n] != p[t]) break;
                    ++n;
                }
                if (n != t) {
                    p.erase(p.begin() + t, p.begin() + n);
                }

                pos = t;
            }

            return p;
        }
    };
}



int test_p10_isMatch() {
    using namespace p10;

    string s, p;

    s = "aaa";
    p = "a*a";
    cout << Solution().isMatch(s, p) << endl;

    s = "aa";
    p = "a";
    cout << Solution().isMatch(s, p) << endl;

    s = "aa";
    p = "a*";
    cout << Solution().isMatch(s, p) << endl;

    s = "aa";
    p = ".*";
    cout << Solution().isMatch(s, p) << endl;

    s = "aab";
    p = "c*a*b";
    cout << Solution().isMatch(s, p) << endl;

    s = "mississippi";
    p = "mis*is*p*.";
    cout << Solution().isMatch(s, p) << endl;

    return 0;
}
