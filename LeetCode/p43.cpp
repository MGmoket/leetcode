/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

namespace p43 {
    class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1.at(0) == '0' || num2.at(0) == '0') return "0";

            vector<string> lines;
            int maxLength = 0;
            for (int j = num2.length(); j > 0; --j) {
                string line = string(num2.length() - j, '0') + multiply(num1, num2[j - 1]);
                lines.push_back(line);
                if (line.length() > maxLength) maxLength = line.length();
            }

            return addnums(lines, maxLength);
        }

    private:

        string multiply(string num, char c) {
            if ('0' == c) return "0";
            int preStep = 0;
            int y = c - '0';

            string res;
            for (int i = num.length(); i > 0; --i) {
                int x = num[i - 1] - '0';
                int z = x * y + preStep;
                res.push_back('0' + z % 10);
                preStep = z / 10;
            }
            if (preStep != 0) {
                res.push_back(preStep + '0');
            }
            return res;
        }

        string addnums(vector<string>& nums, int maxLength) {

            stack<int> temp;
            int preStep = 0;

            for (size_t i = 0; i < maxLength; ++i) {
                int z = preStep;
                for (auto num : nums) {
                    if (num.length() < i + 1) continue;
                    z += num[i] - '0';
                }
                temp.push(z % 10);
                preStep = z / 10;
            }
            while (preStep != 0) {
                temp.push(preStep % 10);
                preStep /= 10;
            }

            string result = string(temp.size(),'0');
            int idx = 0;
            while (!temp.empty()) {
                result[idx++] = temp.top() + '0';
                temp.pop();
            }
            return result;
        }
    };


    // 方法二：优化竖式
    class Solution2 {
    public:
        string multiply(string num1, string num2) {
            if (num1.at(0) == '0' || num2.at(0) == '0') return "0";

            vector<int> res(num1.length() + num2.length(), 0);

            for (int i = num1.length() - 1; i >= 0; --i) {
                int n1 = num1.at(i) - '0';
                for (int j = num2.length() - 1; j >= 0; --j) {
                    int n2 = num2.at(j) - '0';
                    int sum = (res[i+j+1] + n1*n2);
                    res[i + j + 1] = sum % 10;
                    res[i + j] += sum / 10;
                }
            }

            string result;
            for (int i = 0; i < res.size(); ++i) {
                if (result.empty() && res[i] == 0) continue;
                result.push_back((res[i]) + '0');
            }
            return result;
        }
    };
}

int test_p43_multiply() {
    using namespace p43;

    string num1, num2;

    num1 = "123";
    num2 = "456";
    cout << num1 << " * " << num2 << " = " << Solution2().multiply(num1, num2) << endl;

    num1 = "2";
    num2 = "3";
    cout << num1 << " * " << num2 << " = " << Solution2().multiply(num1, num2) << endl;

    return 0;
}
