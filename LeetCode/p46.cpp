/*


Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"

using namespace std;

namespace p46 {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            if (nums.size() <= 1) return { nums };
            return permute(nums, 0, nums.size());
        }

    private:
        vector<vector<int>> permute(vector<int>& nums, int start, int end) {
            if (end - start == 1) {
                return { { nums[start] } };
            }
            else {
               auto res = permute(nums, start + 1, end);
               
               vector<vector<int>> result;
               for (int i = 0; i < end - start; ++i) {
                   for (auto v : res) {
                       v.insert(v.begin() + i, nums[start]);
                       result.push_back(v);
                   }
               }
               return result;
            }
        }
    };
}

int test_p46_permute() {

    using namespace p46;

    vector<int> nums;
    vector<vector<int>> result;

    nums = { 1,2,3 };

    println(nums.begin(), nums.end());
    cout << endl;
    result = Solution().permute(nums);

    for (auto v : result) {
        println(v.begin(), v.end());
    }

    return 0;
}
