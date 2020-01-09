/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p33 {

    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if (nums.size() == 0) return -1;
            return search(nums, 0, nums.size() - 1, target);
        }

    private:
        int search(vector<int>& nums, int start, int end, int target) {
            if (end < start) return -1;
            int mid = (start + end) >> 1;
            
            int first = nums[start];
            int last = nums[end];
            int middle = nums[mid];

            if (target == middle) return mid;
            if (target < middle) {
                if (first > middle) {
                    return search(nums, start, mid - 1, target);
                }
                else if (first <= target) {
                    return search(nums, start, mid - 1, target);
                }
                else {
                    return search(nums, mid+1, end, target);
                }
            }
            else {
                if (first < middle) {
                    return search(nums, mid + 1, end, target);
                }
                else if (last >= target) {
                    return search(nums, mid + 1, end, target);
                }
                else {
                    return search(nums, start, mid - 1, target);
                }
            }
        }

    };


    class Solution2 { // 极品啊
    public:
        int search(vector<int>& nums, int target) {
            int lo = 0, hi = nums.size() - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                    lo = mid + 1;
                else
                    hi = mid;
            }
            return lo == hi && nums[lo] == target ? lo : -1;
        }
    };

}


int test_p33_search() {

    using namespace p33;
    vector<int> nums;
    int idx = -1;

    nums = { 4 };
    println(nums.begin(), nums.end());
    cout << Solution().search(nums, 4) << endl;

    nums = { 4,5,6,7,0,1,2,3};
    println(nums.begin(), nums.end());
    cout << Solution().search(nums, 3) << endl;

    nums = { 4, 5, 6, 7, 8, 1, 2, 3 };
    println(nums.begin(), nums.end());
    cout << Solution().search(nums, 8) << endl;

    nums = { 5,1,3 };
    println(nums.begin(), nums.end());
    cout << Solution().search(nums, 3) << endl;

    nums = { 5,1,2,3,4 };
    println(nums.begin(), nums.end());
    cout << Solution().search(nums, 1) << endl;
    return 0;
}
