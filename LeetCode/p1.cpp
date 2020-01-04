
/**
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.

    ��Դ�����ۣ�LeetCode��
    ���ӣ�https://leetcode-cn.com/problems/two-sum
    ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#include <vector>
#include <unordered_map>
#include <iterator>
#include <iostream>

#include "myprint"

using namespace std;

namespace p1{

    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0) return res;

        unordered_map<int, int> idxs;
        idxs[nums[0]] = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            int want = target - nums[i];
            if (idxs.count(want) > 0) {
                res.push_back(idxs[want]);
                res.push_back(i);
                break;
            }
            idxs[nums[i]] = i;
        }

        return res;
    }
};

}


int test_p1() {

    vector<int> nums = { 2,7,11,15 };
    vector<int> result = p1::Solution().twoSum(nums, 9);
    println(result.begin(), result.end());

    return 0;
}
