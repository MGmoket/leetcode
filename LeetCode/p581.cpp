/*

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"


using namespace std;

namespace p581 {
    class Solution {
    public:
        int findUnsortedSubarray(vector<int>& nums) {
            if (nums.size() < 2) return 0;

            int len = nums.size();
            int max = nums[0];
            int min = nums[len - 1];
            int l = 0, r = -1;
            for (int i = 0; i < len; ++i) {
                if (max > nums[i]) {
                    r = i;
                }
                else {
                    max = nums[i];
                }

                if (min < nums[len - i - 1]) {
                    l = len - i - 1;
                }
                else {
                    min = nums[len - i - 1];
                }

            }

            return r - l + 1;
        }
    };
}


int test_p581_findUnsortedSubarray() {
    using namespace p581;
    vector<int> nums;

    nums = { 2, 6, 4, 8, 10, 9, 15 };
    cout << Solution().findUnsortedSubarray(nums) << endl;

    return 0;
}