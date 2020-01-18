/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace p136 {
    class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            
            sort(nums.begin(), nums.end());
            for (size_t i = 0; i < nums.size()-1; i+=2) {
                if (nums[i] != nums[i + 1]) return nums[i];
            }

            return nums.back();
        }
    };

    class Solution2 {
    public:
        int singleNumber(vector<int>& nums) {

            for (int i = 0; i < nums.size() - 1; ++i) {
                nums[i + 1] = nums[i] ^ nums[i + 1];
            }

            return nums.back();
        }
    };
}

int test_p136_singleNumber() {
    using namespace p136;

    vector<int> nums;

    nums = { 2,2,1 };
    cout << Solution2().singleNumber(nums) << endl;

    nums = { 4,1,2,1,2 };
    cout << Solution2().singleNumber(nums) << endl;
    nums = { 1,2,4,1,2 };
    cout << Solution2().singleNumber(nums) << endl;

    return 0;
}
