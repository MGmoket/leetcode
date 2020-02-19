
#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p75 {

}

class Solution {
public:
    /*
    ������ɫ�������
    */
    void sortColors(vector<int>& nums) {
        // �������� idx < p0 : nums[idx < p0] = 0
        // curr �ǵ�ǰ����Ԫ�ص��±�
        int p0 = 0, curr = 0;
        // �������� idx > p2 : nums[idx > p2] = 2
        int p2 = nums.size() - 1;

        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[p0++]);
            }
            else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2--]);
            }
            else curr++;
        }
    }
};

int test_p75_sortColors() {

    using namespace p75;
    vector<int> nums;

    nums = { 2,0,2,1,1,0 };
    Solution().sortColors(nums);
    println(nums.begin(), nums.end());

    return 0;
}

