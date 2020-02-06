/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p3 {

}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t maxLen = 0;

        int j = 0;

        vector<char> p;

        while (j < s.length()) {
            char ch = s.at(j);
            auto finder = find(p.begin(), p.end(), ch);
            if (finder != p.end()) {
                maxLen = max(maxLen, p.size());
                p.erase(p.begin(), ++finder);
            }
            p.push_back(ch);
            ++j;
        }

        return max(maxLen, p.size());
    }
};

int test_p3_lengthOfLongestSubstring() {
    using namespace p3;

    string s;

    s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    s = "bbbbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    s = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s) << endl;

    return 0;
}
