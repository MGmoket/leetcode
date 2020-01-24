/*

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace p217 {
    class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> rcds;
            for (auto it : nums) {
                if (++rcds[it] > 1) return true;
            }
            return false;
        }
    };
}

int test_p217_containsDuplicate() {
    using namespace p217;
    vector<int> nums;

    nums = { 1,2,3,1 };
    cout << Solution().containsDuplicate(nums) << endl;

    nums = { 1,2,3,4 };
    cout << Solution().containsDuplicate(nums) << endl;

    nums = { 1,1,1,3,3,4,3,2,4,2 };
    cout << Solution().containsDuplicate(nums) << endl;

    return 0;
}
