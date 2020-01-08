/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p26 {

    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
            size_t j = 0;
            size_t k = nums[0];

            for (size_t i = 1; i < nums.size(); ++i) {
                if ( k == nums[i] ) continue;
                k = nums[++j] = nums[i];
            }
            return j+1;
        }
    };

}

int test_p26_removeDuplicates() {
    using namespace p26;

    vector<int> nums;
    nums = { 1,1,2 };
    int len = Solution().removeDuplicates(nums);
    println(nums.begin(), nums.begin() + len);

    nums = { 0,0,1,1,1,2,2,3,3,4};
    len = Solution().removeDuplicates(nums);
    println(nums.begin(), nums.begin() + len);

    nums = { 0 };
    len = Solution().removeDuplicates(nums);
    println(nums.begin(), nums.begin() + len);



    return 0;
}
