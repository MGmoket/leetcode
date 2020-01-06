/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "myprint"

using namespace std;

namespace p16 {

    class Solution0 { // 我的错误版本
    public:
        /*
            基本思路：
                1，排序
                2，穷举
                3，遇到0，直接就结束
                4，考虑左右边界
                5，在左右交界处停止
        */
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

            if (nums.size() < 3) return -1;

            int pre_sm = nums[0] + nums[1] + nums[2];
            int post_sm = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
            if (nums.size() == 3 || pre_sm > target) return pre_sm;
            if (post_sm < target) return post_sm;

            int cl = pre_sm - target;
            int cr = post_sm - target;

            for (size_t i = 0; i < nums.size() - 2; ++i) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;

                for (size_t j = i + 1; j < nums.size() - 1; ++j) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                    size_t k = j + 1;
                    int sum = 0;
                    while (k < nums.size()
                        && (sum = nums[i] + nums[j] + nums[k++]) < target
                        )
                    {
                        ;
                    }

                    if (sum == target) return target;
                    else if (sum < target) {
                        if ((sum - target) > cl) {
                            cl = sum - target;
                        }
                    }
                    else {
                        if ((sum - target) < cr) {
                            cr = sum - target;
                        }
                    }
                }
            }

            if (abs(cl) > abs(cr)) {
                return target + cr;
            }
            return target + cl;
        }
    };

    class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());

            int ans = nums[0] + nums[1] + nums[2];
            for (size_t i = 0; i < nums.size(); ++i) {
                size_t start = i + 1;
                size_t end = nums.size() - 1;

                while (start < end) {
                    int sum = nums[start] + nums[end] + nums[i];
                    if (abs(target - sum) < abs(target - ans)) {
                        ans = sum;
                    }
                    if (sum > target) {
                        end--;
                    }
                    else if (sum < target) {
                        start++;
                    }
                    else return ans;
                }
            }

            return ans;
        }
    };

}


int test_p16_threeSumClosest() {
    using namespace p16;

    vector<int> nums;

    nums = { -1,2,2,-4 };
    println(nums.begin(), nums.end());
    cout << Solution().threeSumClosest(nums, 1) << endl << endl;

    nums = { 1,1,1,1 };
    println(nums.begin(), nums.end());
    cout << Solution().threeSumClosest(nums, 0) << endl << endl;

    nums = { 1,1,1,1 };
    println(nums.begin(), nums.end());
    cout << Solution().threeSumClosest(nums, 100) << endl << endl;

    nums = { -1, 0, 1, 1, 55 };
    println(nums.begin(), nums.end());
    cout << Solution().threeSumClosest(nums, 3) << endl << endl;
    return 0;
}

