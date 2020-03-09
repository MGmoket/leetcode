/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"
using namespace std;

namespace p18 {
    class Solution0 {// error. 有重复元素
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());

            for (int i = 0; i < n - 3; ++i) {
                for (int j = i + 1; j < n - 2; ++j) {
                    for (int k = j + 1; k < n - 1; ++k) {
                        int v = target - nums[i] - nums[j] - nums[k];
                        auto finder = find(nums.begin() + (k + 1), nums.end(), v);
                        if (finder != nums.end()) {
                            result.push_back({ nums[i], nums[j], nums[k], *finder });
                        }
                    }
                }
            }
            return result;
        }
    };

    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            int size = nums.size();
            for (int a = 0; a < size - 3; ++a)
            {
                if (a > 0 && nums[a] == nums[a - 1])continue;
                for (int b = a + 1; b < size - 2; ++b)//以下代码与三数之和一样的
                {
                    if (b > a + 1 && nums[b] == nums[b - 1])continue;
                    int i = b + 1, j = size - 1;
                    while (i < j)
                    {
                        int sum = nums[a] + nums[b] + nums[i] + nums[j];
                        if (sum < target)
                            while (i < j && nums[i] == nums[++i]);
                        else if (sum > target)
                            while (i < j && nums[j] == nums[--j]);
                        else {
                            result.push_back(vector<int>{nums[a], nums[b], nums[i], nums[j]});
                            while (i < j && nums[i] == nums[++i]);
                            while (i < j && nums[j] == nums[--j]);
                        }
                    }
                }
            }
            return result;
        }
    };
}


int test_p18_fourSum() {
    using namespace p18;
    vector<int> nums;
    int target;
    vector<vector<int>> res;

    nums = { 1, 0, -1, 0, -2, 2 };
    target = 0;
    res = Solution().fourSum(nums, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    nums = { -1,0,1,2,-1,-4 };
    target = -1;
    res = Solution().fourSum(nums, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    nums = { -3,-2,-1,0,0,1,2,3 };
    target = 0;
    res = Solution().fourSum(nums, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }
    return 0;
}
