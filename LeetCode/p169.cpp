/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace p169 {
    class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int threhold = nums.size() / 2 + nums.size() % 2;

            map<int, int> recds;
            for (auto it : nums) {
                if (++recds[it] == threhold) return it;
            }
            return -1;
        }
    };
}

int test_p169_majorityElement() {
    using namespace p169;

    vector<int>nums;

    nums = { 3,2,3 };
    cout << Solution().majorityElement(nums) << endl;

    nums = { 2,2,1,1,1,2,2 };
    cout << Solution().majorityElement(nums) << endl;

    return 0;
}
