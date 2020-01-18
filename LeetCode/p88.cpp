/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p88 {
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i1 = m - 1;
            int i2 = n - 1;
            int p = m + n - 1;

            while (i2 >= 0) {
                if (i1 >= 0 && nums1[i1] > nums2[i2]) {
                    nums1[p--] = nums1[i1--];
                }
                else {
                    nums1[p--] = nums2[i2--];
                }
            }
        }
    };
}

int test_p88_merge() {
    using namespace p88;
    vector<int> nums1, nums2;

    int m = 3;
    int n = 3;

    nums1 = { 1,2,3,0,0,0 };
    nums2 = { 2,5,6 };

    Solution().merge(nums1, m, nums2, n);
    println(nums1.begin(), nums1.end());


    return 0;
}
