/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

#include "myprint"

using namespace std;
namespace p215 {
    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            vector<int> tmp(nums.begin(), nums.begin() + k);
            sort(tmp.begin(), tmp.end());
            for (size_t i = k; i < nums.size(); ++i) {
                insert(tmp, nums[i]);
            }
            return tmp.front();
        }
    private:
        void insert(vector<int>& nums, int t) {
            for (int i = nums.size()-1; i >= 0; --i) {
                if (nums[i] < t) {
                    swap(nums[i], t);
                }
            }
        }
    };

    class Solution2 {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            return nums[k - 1];
        }
    };
    class Solution3 {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> q;
            for (int v : nums) {
                if (q.size() < k) {
                    q.push(v);
                }
                else if (v > q.top()) {
                    q.push(v);
                    q.pop();
                }
            }
            return q.top();
        }
    };
}

int test_p215_findKthLargest() {
    using namespace p215;
    vector<int> nums;
    int k = 0;
    int v = 0;

    nums = { 3,2,1,5,6,4 };
    k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;

    nums = { 3,2,3,1,2,4,5,5,6 };
    k = 4;
    cout << Solution().findKthLargest(nums, k) << endl;

    return 0;
}
