/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

#include "myprint"

using namespace std;

namespace p40 {
    class Solution {
    public:
        void backtrack(vector<int>& candidates, int target, int sum, int begin) {
            if (sum == target) {
                res.push_back(nums);
                return;
            }
            else
                while (begin < candidates.size() && sum + candidates[begin] <= target) {
                    nums.push_back(candidates[begin]);
                    backtrack(candidates, target, sum + candidates[begin++], begin);
                    //回溯前去重
                    while (begin < candidates.size() && candidates[begin] == candidates[begin - 1]) ++begin;
                    nums.pop_back();//回溯，进行下一位运算  
                }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            if (candidates.empty()) { return res; }
            sort(candidates.begin(), candidates.end());
            backtrack(candidates, target, 0, 0);
            return res;
        }
    private:
        vector<vector<int>> res;
        vector<int> nums;
    };
}



int test_p40_combinationSum2() {
    using namespace p40;
    vector<int> candidates;
    int target;
    vector<vector<int>> res;

    candidates = { 10,1,2,7,6,1,5 };
    target = 8;
    res = Solution().combinationSum2(candidates, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    cout << endl;
    candidates = { 2,5,2,1,2 };
    target = 5;
    res = Solution().combinationSum2(candidates, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    return 0;
}
