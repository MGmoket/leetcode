/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/generate-parentheses
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <vector>
#include <string>
using namespace std;

namespace p22 {

    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            if (n == 0) return {};
            if (n == 1) return { "()" };
            vector<vector<string>> dp(n + 1);
            dp[0] = { "" };
            dp[1] = { "()" };
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    for (string p : dp[j])
                        for (string q : dp[i - j - 1]) {
                            string str = "(" + p + ")" + q;
                            dp[i].push_back(str);
                        }
                }
            }
            return dp[n];
        }
    };
}



int test_p22_generateParenthesis() {
    using namespace p22;

    return 0;
}
