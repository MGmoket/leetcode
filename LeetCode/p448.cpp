/*
Given an array of integers where 1 �� a[i] �� n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"

using namespace std;

namespace p448 {

    class Solution2 {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            vector<int> output;
            int pre = 0;
            int i = 0;
            while (i < nums.size())
            {
                while (nums[i] == pre) {
                    ++i;
                }
                if (nums[i] - pre > 1) {
                    for (int j = pre + 1; j < nums[i]; ++j) {
                        output.push_back(j);
                    }
                }
                pre = nums[i];
                ++i;
            }

            for (i = pre + 1; i < nums.size() + 1; ++i) {
                output.push_back(i);
            }

            return output;
        }
    };

    class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> res;
            if (nums.empty()) return nums;
            for (int i = 0; i < nums.size(); i++)
            {
                int index = (nums[i] - 1) % nums.size();
                nums[index] += nums.size();
            }
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= nums.size())
                    res.push_back(i + 1);
            }
            return res;
        }
    };
}


int test_p448_findDisappearedNumbers() {
    using namespace p448;

    vector<int> nums, res;

    nums = { 4,3,2,7,8,2,3,1 };
    res = Solution().findDisappearedNumbers(nums);
    println(res.begin(), res.end());

    return 0;
}

