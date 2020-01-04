/**
 * 

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 */

#include <vector>
#include <iostream>
#include "myprint"

using namespace std;

namespace p4 {
    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int pos1 = 0;
            int pos2 = 0;
            int total = nums1.size() + nums2.size();

            int remain = total / 2;
            while (int mid = (remain / 2))
            {
                if (pos1 + mid > nums1.size()) {
                    pos2 += mid;
                    remain -= mid;
                    continue;
                }
                if (pos2 + mid > nums2.size()) {
                    pos1 += mid;
                    remain -= mid;
                    continue;
                }

                if (nums1[pos1 + mid - 1] <= nums2[pos2 + mid - 1]) {
                    pos1 += mid;
                }
                else {
                    pos2 += mid;
                }

                remain -= mid;
            }


            if (total % 2 == 0) {
                if (pos1 >= nums1.size()) {
                    return ((double)nums2[pos2] + nums2[pos2 + 1]) / 2;
                }
                else if (pos2 >= nums2.size()) {
                    return ((double)nums1[pos1] + nums1[pos1] + 1) / 2;
                }
                else {
                    if (pos1 == nums1.size() - 1 && pos2 == nums2.size() - 1) {
                        return mid(nums1[pos1], nums2[pos2]);
                    }
                    else if (nums1[pos1] <= nums2[pos2]) {
                        if (pos1 == nums1.size() - 1) return mid(nums1[pos1], nums2[pos2]);
                        else return mid(nums1[pos1], minNum(nums1[pos1 + 1], nums2[pos2]));
                    }
                    else {
                        if (pos2 == nums2.size() - 1) return mid(nums1[pos1], nums2[pos2]);
                        else return mid(nums2[pos2], minNum(nums2[pos2 + 1], nums1[pos1]));
                    }
                }
            }
            else {
                if (pos1 >= nums1.size()) return nums2[pos2 + remain];
                else if (pos2 >= nums2.size())return nums1[pos1 + remain];
                else {
                    if (nums1[pos1] <= nums2[pos2]) {
                        if (pos1 == nums1.size() - 1) return nums2[pos2];
                        else return minNum(nums1[pos1 + 1], nums2[pos2]);
                    }
                    else {
                        if (pos2 == nums2.size() - 1) return nums1[pos1];
                        else return minNum(nums1[pos1], nums2[pos2 + 1]);
                    }
                }
            }
        }

    private:
        int minNum(int a, int b) {
            return a <= b ? a : b;
        }
        int maxNum(int a, int b) {
            return a <= b ? b : a;
        }
        double mid(int a, int b) {
            return ((double)a + b) / 2;
        }
    };
}


int test_p4_findMedianSortedArrays() {
    using namespace p4;

    vector<int> nums1, nums2;
    double mid = 0.0f;

    nums1 = { 1,3 };
    nums2 = { 2 };

    println(nums1.begin(), nums1.end(), "nums1: [");
    println(nums2.begin(), nums2.end(), "nums2: [");
    mid = Solution().findMedianSortedArrays(nums1, nums2);
    cout << "mid: " << mid << endl << endl;

    nums1 = { 1,2 };
    nums2 = { 3,4 };

    println(nums1.begin(), nums1.end(), "nums1: [");
    println(nums2.begin(), nums2.end(), "nums2: [");
    mid = Solution().findMedianSortedArrays(nums1, nums2);
    cout << "mid: " << mid << endl;

    return 0;
}
