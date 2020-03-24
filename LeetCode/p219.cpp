
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

namespace p219 {

    class Solution0 {// over time.
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            if (nums.size() == 0) return false;
            for (size_t i = 0; i < nums.size() - 1; ++i) {
                size_t END = min(nums.size(), i + k + 1);
                if (find(nums.begin() + i + 1, nums.begin() + END, nums[i]) != nums.begin() + END) return true;
            }

            return false;
        }
    };

    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int n = nums.size(), idx = 0;
            unordered_map<int, int> nmap; // key:nums[i], value:index
            for (int i = 0; i < n; ++i) {
                auto iter = nmap.find(nums[i]);
                if (iter != nmap.end()) {
                    if (i - iter->second <= k) return true;
                    else iter->second = i;
                }
                else nmap[nums[i]] = i;
            }
            return false;
        }
    };
}



int test_p219_containsNearbyDuplicate() {
    using namespace p219;

    vector<int> nums;

    nums = { 1,2,3,1 };
    cout << Solution().containsNearbyDuplicate(nums, 3);

    nums = { 1,0,1,1 };
    cout << Solution().containsNearbyDuplicate(nums, 1);

    nums = { 1,2,3,1,2,3 };
    cout << Solution().containsNearbyDuplicate(nums, 2);
    return 0;
}
