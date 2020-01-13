/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "myprint"

using namespace std;

namespace p53 {
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if (nums.size() == 0) return 0;

            int ans = nums[0];
            int sum = 0;
            for (auto num : nums) {
                if (sum > 0) {
                    sum += num;
                }
                else {
                    sum = num;
                }

                ans = max(ans, sum);
            }

            return ans;
        }
    };
}

int test_p53_maxSubArray() {

    using namespace p53;
    vector<int> nums;

    nums = { -2,1,-3,4,-1,2,1,-5,4 };
    println(nums.begin(), nums.end());
    cout << Solution2().maxSubArray(nums) << endl;

    return 0;
}
