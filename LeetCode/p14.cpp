/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace p14 {

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs.front();

        string cmm;
        size_t len = strs.front().length();

        try {
            for (size_t i = 0; i < len; ++i) {
                char c = strs[0][i];
                bool b = true;
                for (size_t j = 1; j < strs.size(); ++j) {
                    if (strs.at(j).at(i) != c) {
                        b = false;
                        break;
                    }
                }
                if (!b) break;
                cmm.push_back(c);
            }
        }
        catch (exception & e) {
            ;// nothing
        }

        return cmm;
    }
};

}
int test_p14_longestCommonPrefix() {
    using namespace p14;
    vector<string> strs = { "flower","flow","flight" };
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}

