/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/move-zeroes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p283 {
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                if (nums[j] == 0) {
                    if (nums[i] != 0) {
                        swap(nums[j], nums[i]);
                        ++j;
                    }
                }
                else if (nums[i] != 0) {
                    ++j;
                }
            }
        }
    };
}

int test_p283_moveZeroes() {
    using namespace p283;
    vector<int> nums;

    nums = { 0,1,0,3,12 };
    Solution().moveZeroes(nums);
    println(nums.begin(), nums.end());

    return 0;
}
