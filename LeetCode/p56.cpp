/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "myprint"

using namespace std;
namespace p56 {

}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(),
            [&, this](vector<int>& v1, vector<int>& v2) { return v1.front() < v2.front(); });

        vector<vector<int>> res;
        vector<int> pre = intervals.front();
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (pre.back() >= intervals[i].front()) {
                pre[0] = min(pre[0], intervals[i][0]);
                pre[1] = max(pre[1], intervals[i][1]);
            }
            else {
                res.push_back(pre);
                pre = intervals[i];
            }
        }

        res.push_back(pre);
        return res;
    }
};

int test_p56_merge() {
    using namespace p56;
    vector<vector<int>> intervals, res;

    intervals = { {1,3},{2,6},{8,10},{15,18} };
    res = Solution().merge(intervals);

    for (auto it : res) {
        println(it.begin(), it.end());
    }

    intervals = { {1,4},{4,5} };
    res = Solution().merge(intervals);

    for (auto it : res) {
        println(it.begin(), it.end());
    }

    intervals = { {1,3},{2,4} };
    res = Solution().merge(intervals);

    for (auto it : res) {
        println(it.begin(), it.end());
    }

    intervals = { {1,3},{0,0} };
    res = Solution().merge(intervals);

    for (auto it : res) {
        println(it.begin(), it.end());
    }

    return 0;
}
