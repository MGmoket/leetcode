/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>

using namespace std;

namespace p20 {
    class Solution {
    public:
        bool isValid(string s) {
            if (s.length() % 2 != 0) return false;
            if (s.length() == 0) return true;

            stack<int> remains;
            for (size_t i = 0; i < s.length(); ++i) {
                char c = s[i];
                if (remains.empty()) {
                    if (!isLeft(c))return false;
                    else remains.push(c);
                }
                else {
                    if (isMatched(remains.top(), c)) {
                        remains.pop();
                    }
                    else {
                        remains.push(c);
                    }
                }
            }
            return remains.empty();
        }

    private:
        bool isMatched(char a, char b) {
            return (a == '(' && b == ')'
                || a == '[' && b == ']'
                || a == '{' && b == '}');
        }

        bool isLeft(char c) {
            return c == '(' || c == '[' || c == '{';
        }
    };
}

int test_p20_isValid() {
    using namespace p20;

    string input;

    input = "()";
    cout << Solution().isValid(input) << endl << endl;

    input = "()[]{}";
    cout << Solution().isValid(input) << endl << endl;

    input = "([)]{}";
    cout << Solution().isValid(input) << endl << endl;


    return 0;
}
