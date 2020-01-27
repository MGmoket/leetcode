/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

#include <iostream>
#include <string>

using namespace std;
namespace p557 {
    class Solution {
    public:
        string reverseWords(string s) {
            string res;
            string t;
            for (auto ch : s) {
                if (ch != ' ') {
                    t.push_back(ch);
                }
                else {
                    res += reverseWord(t);
                    t.clear();
                    res.push_back(ch);
                }
            }
            
            if (!t.empty()) {
                res += reverseWord(t);
                t.clear();
            }
            return res;
        }
    private:
        string reverseWord(string s) {
            reverse(s.begin(), s.end());
            return s;
        }
    };
}

int test_p557_reverseWords() {
    using namespace p557;
    string s;

    s = "Let's take LeetCode contest";
    s = Solution().reverseWords(s);
    cout << s << endl;

    s.clear();
    s = Solution().reverseWords(s);
    cout << s << endl;

    return 0;
}

