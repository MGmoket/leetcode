/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include "myprint"

using namespace std;
namespace p152 {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int imax = 1;
            int imin = 1;

            int maxVal = INT_MIN;
            for (int v : nums) {
                if (v < 0) {
                    swap(imin, imax);
                }
                imax = max(v, imax * v);
                imin = max(v, imin * v);

                maxVal = max(maxVal, imax);
            }
            return maxVal;
        }
    };
}

int test_p152_maxProduct() {
    using namespace p152;
    vector<int> nums;

    nums = { 2,3,-2,4 };
    cout << Solution().maxProduct(nums) << endl;

    nums = { -2,0,-1 };
    cout << Solution().maxProduct(nums) << endl;

    nums = {1,2,4,-1,3,0,8,2,1,};
    cout << Solution().maxProduct(nums) << endl;

    return 0;
}
