/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p31 {

}

class Solution {
public:
    inline void iter_swap(vector<int>::iterator a, vector<int>::iterator b) { int t = *a; *a = *b; *b = t; }
    bool Next_permutation(vector<int>::iterator a, vector<int>::iterator b) {
        // 空
        if (a == b) return false;
        // 只有一个元素
        vector<int>::iterator i = a; ++i;
        if (i == b) return false;

        i = b; --i;
        while (true) {
            vector<int>::iterator j = i;
            --i;
            if (*i < *j) { // 寻找a[k] < a[k + 1]的过程
                vector<int>::iterator k = b;
                while (!(*i < *--k))/*pass*/; //寻找 a[l] > a[k]的过程
                iter_swap(i, k);
                reverse(j, b);
                return true;
            }
            if (i == a) { // 假如没找到
                reverse(a, b);
                return false;
            }
        }

    }
    void nextPermutation(vector<int>& nums) {
        Next_permutation(nums.begin(), nums.end());
    }
};

int test_p31_nextPermutation() {
    using namespace p31;
    vector<int> nums;
    nums = { 1,2,3 };
    println(nums.begin(), nums.end());
    Solution().nextPermutation(nums);
    println(nums.begin(), nums.end());
    return 0;
}
