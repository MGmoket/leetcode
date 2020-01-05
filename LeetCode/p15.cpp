/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "myprint"

using namespace std;

namespace p15 {
    class Solution {// 该版本超时
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {

            vector<vector<int>> res;
            if (nums.size() < 3) return res;

            sort(nums.begin(), nums.end());
            for (size_t i = 0; i < nums.size() - 2; ++i) {
                int x = nums[i];
                if (x > 0) break;
                if (i > 0 && x == nums[i - 1]) continue;

                for (size_t j = i + 1; j < nums.size() - 1; ++j) {

                    int y = nums[j];
                    if ( j-1!= i && y == nums[j-1] ) continue;

                    int z = 0 - x - y;
                    if (z < y) continue;

                    auto finder = find(nums.begin() + (j + 1), nums.end(), z);
                    if (finder != nums.end()) {
                        res.push_back({ x,y,z });
                    }
                }
            }

            return res;
        }
    };


    class Solution2 {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {

            vector<vector<int>> res;
            if (nums.size() < 3) return res;

            sort(nums.begin(), nums.end());
            if (nums.back() < 0) return res;

            for (size_t i = 0; i < nums.size() - 2; ++i) {
                int x = nums[i];
                if (x > 0) break;
                if (i > 0 && x == nums[i - 1]) continue;

                int L = i + 1;
                int R = nums.size() - 1;

                while (L < R) {
                    int sum = x + nums[L] + nums[R];
                    if (sum == 0) {
                        res.push_back({ x, nums[L], nums[R] });
                        while (L < R && nums[L] == nums[L + 1]) ++L;
                        while (L < R && nums[R] == nums[R - 1]) --R;
                        ++L;
                        --R;
                    }
                    else if (sum > 0) --R;
                    else ++L;
                }
            }

            return res;
        }
    };
}

int test_p15_threeSum() {
    using namespace p15;
    
    vector<int> nums;
    vector<vector<int>> res;

    nums = { -1, 0, 1, 2, -1, -4 };
    res = Solution2().threeSum(nums);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    cout << endl;

    nums = { 0,0,0,0 };// mutipled
    res = Solution2().threeSum(nums);
    for (auto it : res) {
        println(it.begin(), it.end());
    }
    cout << endl;

    nums = { -1,-1,-1,-1,2,2,2,2,2};
    res = Solution2().threeSum(nums);
    for (auto it : res) {
        println(it.begin(), it.end());
    }
    cout << endl;
    nums = {};          // crashed
    res = Solution2().threeSum(nums);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    return 0;
}
