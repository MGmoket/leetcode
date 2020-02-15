/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#include "myprint"

using namespace std;

namespace p49 {

    class Solution0 {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mps;

            for (auto str : strs) {
                string idx = getStrIdx(str);
                mps[idx].push_back(str);
            }

            vector<vector<string>> res;
            for (auto it : mps) {
                res.push_back(it.second);
            }
            return res;
        }
    private:
        string getStrIdx(const string& str) {
            vector<int> idxs(26);
            for (auto ch : str) {
                idxs[ch - 'a']++;
            }
            string res;
            for (auto id : idxs) {
                res += to_string(id);
            }
            return res;
        }
    };


    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, int> mps;
            vector<vector<string>> res;

            int idex = 0;

            for (auto str : strs) {
                string tmp = str;
                sort(tmp.begin(), tmp.end());

                int i = mps[tmp];
                if (i == 0) {
                    vector<string> v(1);
                    v.push_back(str);
                    res.push_back(v);
                    mps[tmp] = ++idex;
                }
                else {
                    res[i - 1].push_back(str);
                }
            }

            return res;
        }
    };
}

int test_p49_groupAnagrams() {
    using namespace p49;

    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> res;

    res = Solution().groupAnagrams(strs);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    return 0;
}
