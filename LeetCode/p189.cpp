/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include "myprint"

using namespace std;

namespace p189 {
    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if (nums.size() == 0) return;

            k %= nums.size();
            if (k == 0) return;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k);
            reverse(nums.begin() + k, nums.end());
        }
    };
}

int test_p189_rotate() {
    using namespace p189;
    vector<int> nums;
    int k = 0;

    nums = { 1,2,3,4,5,6,7 };
    k = 3;

    Solution().rotate(nums, k);
    println(nums.begin(), nums.end());

    return 0;
}
