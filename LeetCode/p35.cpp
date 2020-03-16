/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

namespace p35 {

    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            return searchInsert(nums, target, 0, nums.size());
        }
    private:
        int searchInsert(vector<int>& nums, int target, int left, int right) {
            if (right - left == 1) {
                if (nums[left] < target) return left + 1;
                return left;
            }

            int mid = (left + right) >> 1;
            if (nums[mid] == target) return mid;

            int i = mid;
            if (nums[mid] >= target) return searchInsert(nums, target, left, mid);
            return searchInsert(nums, target, mid, right);
        }
    };

}

int test_p35_searchInsert() {
    using namespace p35;
    vector<int> nums;
    int target;
    
    nums = { 1,3,5,6 };
    target = 5;
    cout << Solution().searchInsert(nums, target) << endl;

    nums = { 1,3,5,6 };
    target = 2;
    cout << Solution().searchInsert(nums, target) << endl;

    nums = { 1,3,5,6 };
    target = 7;
    cout << Solution().searchInsert(nums, target) << endl;

    nums = { 1,3,5,6 };
    target = 0;
    cout << Solution().searchInsert(nums, target) << endl;
    

    nums = { 1,3 };
    target = 4;
    cout << Solution().searchInsert(nums, target) << endl;


    return 0;
}
