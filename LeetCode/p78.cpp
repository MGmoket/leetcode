/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp = {};
        subsets(nums, 0, tmp, result);

        return result;
    }

private:
    void subsets(vector<int>& nums, int i, vector<int> tmp, vector<vector<int>>&result) {
        result.push_back(tmp);
        for (int j = i; j < nums.size(); ++j) {
            vector<int> tt(tmp);
            tt.push_back(nums[j]);
            subsets(nums, j + 1, tt, result);
        }
    }
};


int test_p78_subsets() {

    vector<vector<int>> result;
    vector<int> nums;

    nums = {1,2,3};
    result = Solution().subsets(nums);
    for (auto v : result) {
        println(v.begin(), v.end());
    }


    return 0;
}