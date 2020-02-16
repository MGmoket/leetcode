/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"


using namespace std;
namespace p55 {

	class Solution {
	public:
		bool canJump(vector<int>& nums)
		{
			int k = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				if (i > k) return false;
				k = max(k, i + nums[i]);
			}
			return true;
		}
	};
}


int test_p55_canJump() {
    using namespace p55;

    vector<int> nums;

    nums = { 2,5,0,0 };
    cout << Solution().canJump(nums) << endl;

    return 0;
}
