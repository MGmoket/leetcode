/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"

using namespace std;

namespace p238 {
    class Solution2 {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> left(nums.size() ,1);
            vector<int> right(nums.size(),1);
            
            for (int i = 1; i < nums.size(); ++i) {
                left[i] = left[i - 1] * nums[i - 1];
            }

            for (int i = nums.size() - 2; i >= 0; --i) {
                right[i] = right[i + 1] * nums[i + 1];
            }
            
            vector<int> output(nums.size());
            for (int i = 0; i < nums.size(); ++i) {
                output[i] = left[i] * right[i];
            }

            return output;
        }
    };

    class Solution { // 空间复杂度为O(1)
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> output(nums.size(), 1);
            for (int i = 1; i < nums.size(); ++i) {
                output[i] = output[i - 1] * nums[i - 1];
            }

            int right = 1;
            for (int i = output.size() - 1; i >= 0; --i) {
                output[i] *= right;
                right *= nums[i];
            }

            return output;
        }
    };
}

int test_p238_productExceptSelf() {
    using namespace p238;
    vector<int> nums, output;

    nums = { 1,2,3,4 };
    output = Solution2().productExceptSelf(nums);
    println(output.begin(), output.end());
    cout << endl;



    return 0;
}

