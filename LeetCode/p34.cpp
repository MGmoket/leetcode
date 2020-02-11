/*class Solution {
    // returns leftmost (or rightmost) index at which `target` should be
    // inserted in sorted array `nums` via binary search.
    private int extremeInsertionIndex(int[] nums, int target, boolean left) {
        int lo = 0;
        int hi = nums.length;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    public int[] searchRange(int[] nums, int target) {
        int[] targetRange = { -1, -1 };

        int leftIdx = extremeInsertionIndex(nums, target, true);

        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.length || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

        return targetRange;
    }
}*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;
namespace p34 {

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int leftIdx = extremeInsertionIndex(nums, target, true);
            if (leftIdx == nums.size() || nums[leftIdx] != target) return { -1,-1 };
            int rightIdx = extremeInsertionIndex(nums, target, false) - 1;
            return { leftIdx, rightIdx };
        }

    private:
        int extremeInsertionIndex(vector<int>&nums, int target, bool left) {
            int lo = 0;
            int hi = nums.size();

            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (nums[mid] > target || (left && target == nums[mid])) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }

            return lo;
        }
    };
}

int test_p34_searchRange() {
    using namespace p34;

    vector<int> nums, idxs;
    int target = 0;

    nums = { 5,7,7,8,8,10 };
    target = 8;

    println(nums.begin(), nums.end());
    cout << " target=" << target;
    idxs = Solution().searchRange(nums, target);
    println(idxs.begin(), idxs.end());

    return 0;
}