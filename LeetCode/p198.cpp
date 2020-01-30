/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace p198 {
    class Solution {
    public:
        int rob(vector<int>& nums) {
            return rob(nums, 0);
        }
    private:
        int rob(vector<int>& nums, int start) {
            if (start >= nums.size()) return 0;
            int va = nums[start] + rob(nums, start + 2);
            int vb = rob(nums, start + 1);
            return max(va, vb);
        }
    };

    class Solution2 {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            int t1 = 0;
            int t2 = nums[0];
            for (int j = 1; j < nums.size(); ++j){
                int t = t1 + nums[j];
                t1 = t2;
                t2 = max(t, t2);
            }

            return max(t1,t2);
        }
    };
}

int test_p198_rob() {
    using namespace p198;

    vector<int> nums;
    
    nums = {1,2,3,1};
    cout << Solution2().rob(nums) << endl;

    nums = { 2,7,9,3,1 };
    cout << Solution2().rob(nums) << endl;

    nums = {2,1,1,2 };
    cout << Solution2().rob(nums) << endl;

    return 0;
}