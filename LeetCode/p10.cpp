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
            int len1 = s.length(), len2 = p.length();
            bool* dp = new bool[len2 + 1]{};
            dp[0] = true;
            for (int j = 2; j <= len2; j++)
                dp[j] = dp[j - 2] && p[j - 1] == '*';
            for (int i = 1; i <= len1; i++)
            {
                bool t = dp[0];
                dp[0] = false;
                for (int j = 1; j <= len2; j++)
                {
                    bool temp = dp[j];
                    if (p[j - 1] == '.')
                        dp[j] = t;
                    else if (p[j - 1] == '*')
                    {
                        if (p[j - 2] == '.')
                            dp[j] = dp[j - 2] || dp[j];
                        else
                            dp[j] = dp[j - 2] || (dp[j] && p[j - 2] == s[i - 1]);
                    }
                    else
                        dp[j] = t && p[j - 1] == s[i - 1];
                    t = temp;
                }
            }
            bool ret = dp[len2];
            delete[]dp;
            return ret;
        }
    };

    class Solution1 {
    public:
        bool isMatch(string s, string p) {
            vector<vector<bool>> dp(s.length() + 1);
            for (auto& b : dp) {
                b.resize(p.length() + 1);
            }


            dp[0][0] = true;
            for (int i = 0; i < p.length(); i++) {
                if (p[i] == '*' && dp[0][i - 1]) {
                    dp[0][i + 1] = true;
                }
                else {
                    dp[0][i + 1] = false;
                }
            }
            if (s.length() >= 1) {
                for (int i = 1; i < s.length() + 1; i++) {
                    dp[i][0] = false;
                }
            }
            for (int i = 0; i < s.length(); i++) {
                for (int j = 0; j < p.length(); j++) {
                    if (s[i] == p[j] || p[j] == '.') {
                        dp[i + 1][j + 1] = dp[i][j];
                    }
                    else if (p[j] == '*') {
                        if (p[j - 1] != s[i] && p[j - 1] != '.') {
                            dp[i + 1][j + 1] = dp[i + 1][j - 1];
                        }
                        else {
                            if (dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1]) {
                                dp[i + 1][j + 1] = true;
                            }
                            else {
                                dp[i + 1][j + 1] = false;
                            }
                        }
                    }
                    else {
                        dp[i + 1][j + 1] = false;
                    }
                }
            }
            return dp[s.length()][p.length()];
        }
    };


    class Solution0 { // failed
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
