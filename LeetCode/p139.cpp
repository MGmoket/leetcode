/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace p139 {
	class Solution {
	public:
		bool wordBreak(string s, vector<string>& wordDict)
		{
			size_t validEnd = 0;
			vector<bool> dp(s.size() + 1, false);
			dp[0] = true;
			for (size_t i = 0; i < s.size(); i++)
			{
				if (i == validEnd + 1) return false;
				if (!dp[i]) continue;
				for (auto& word : wordDict)
				{
					size_t newEnd = i + word.size();
					if (newEnd > s.size()) continue;
					if (memcmp(&s[i], &word[0], word.size()) == 0)
					{
						dp[newEnd] = true;
						validEnd = max(validEnd, newEnd);
					}
				}
			}
			return dp.back();
		}
	};

}


int test_p139_wordBreak() {
    using namespace p139;

    string s;
    vector<string> wordDict;
    cout << Solution().wordBreak(s, wordDict) << endl;


    return 0;
}


