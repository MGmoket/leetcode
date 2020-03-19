/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

namespace p41 {

    class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == i + 1 || !nums[i]) {
                    continue;
                }
                if (nums[i] > nums.size() || nums[i] < 0) {
                    nums[i] = 0;
                }
                else {
                    int a = nums[i], b = nums[a - 1];
                    while (nums[a - 1] != a) {
                        nums[a - 1] = a;
                        if (b <= 0 || b > nums.size()) {
                            break;
                        }
                        a = b;
                        b = nums[a - 1];
                    }
                    nums[a - 1] = a;
                }
            }
            int res = 0, i = 0;
            for (; i < nums.size(); ++i) {
                if (nums[i] != i + 1) {
                    res = i + 1;
                    break;
                }
            }
            return i == nums.size() ? nums.size() + 1 : res;
        }
    };
}

int test_p41_firstMissingPositive() {
    using namespace p41;
    vector<int> nums;
   
    nums = { 1,2,0 };
    cout << Solution().firstMissingPositive(nums) << endl;


    nums = { 3,4,-1,1 };
    cout << Solution().firstMissingPositive(nums) << endl;


    nums = { 7,8,9,11,12 };
    cout << Solution().firstMissingPositive(nums) << endl;


    return 0;
}

