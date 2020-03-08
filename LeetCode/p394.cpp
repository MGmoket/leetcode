/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

namespace p394 {

class Solution0 {
public:
    string decodeString(string s) {
        string res;
        stack<string> _stack;

        size_t i = 0;
        while (i < s.length()) {
            size_t pos = s.find_first_of("[]", i);

            if (pos < s.length() && s.at(pos) == '[') {
                size_t pos2 = s.find_first_of("0123456789", i);
                string part = s.substr(i, pos2 - i);
                if (pos2 != i) {
                    if (!_stack.empty() && _stack.top().find('[') == std::string::npos) {
                        part = _stack.top() + part;
                        _stack.pop();
                    }
                    _stack.push(part);
                }
               
                _stack.push(s.substr(pos2, pos - pos2+1));// with [
            }
            else {
                string part = s.substr(i, pos - i);
                while (!_stack.empty() && _stack.top().find('[') == std::string::npos) {
                    part = _stack.top() + part;
                    _stack.pop();
                }

                if (!_stack.empty()) {

                    string pre = _stack.top();
                    _stack.pop();
                    int times = atoi(pre.c_str());
                    string newpart = timesPart(part, times);
                    if (_stack.empty() || _stack.top().find('[') != std::string::npos) {
                        _stack.push(newpart);
                    }
                    else {
                        newpart = _stack.top() + newpart;
                        _stack.pop();
                        _stack.push(newpart);
                    }
                }
            }
            i = pos + 1;
        }

        return _stack.top();
    }

private:
    string timesPart(string part, int times) {
        string res;
        for (int i = 0; i < times; ++i) {
            res += part;
        }
        return res;
    }

};

/*

作者：wallcwr
链接：https ://leetcode-cn.com/problems/decode-string/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-47/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    typedef pair<int, string> pis;
    //将字符串str重复times次
    string repeat(const string& str, int times) {
        string retString = "";
        for (int i = 0; i < times; ++i) retString += str;
        return retString;
    }
    //先思考：栈应存储什么元素，何时进栈、出栈
    string decodeString(string s) {
        int repeatTims = 0;
        string res = "";
        vector<pis> vecStack;   //用vector代替stack，更高效，因为stack底层可以是vector
        for (auto i : s) {
            if ('0' <= i && i <= '9') repeatTims = (repeatTims * 10) + (i - '0');  //计算字符串需要重复的次数
            else if (i == '[') {
                vecStack.push_back({ repeatTims,res });
                //进栈后要更新res和repeatTimes，并不担心最后返回的res为空，因为之前更新的res在遇到'['又会被进栈
                //不懂这问题的可以手动模拟一下这个样例：3[a]2[bc]ef
                res = "";
                repeatTims = 0;
            }
            else if (i == ']') {
                pis tmp = vecStack[vecStack.size() - 1];
                vecStack.pop_back();
                res = tmp.second + (tmp.first == 0 ? "" : repeat(res, tmp.first));
            }
            else res += i;
        }
        return res;
    }
};


}

int test_p394_decodeString() {
    using namespace p394;

    cout << Solution().decodeString("3[a]2[bc]") << endl;
    cout << Solution().decodeString("3[a2[c]]") << endl;
    cout << Solution().decodeString("2[abc]3[cd]ef2[c]") << endl;

    return 0;
}