#include <iostream>
#include <vector>
#include <algorithm>

#include "myprint"

using namespace std;

namespace p39 {
    class Solution {
    private:
        vector<int> candidates;
        vector<vector<int>> res;
        vector<int> path;
    public:
        void DFS(int start, int target) {
            if (target == 0) {
                res.push_back(path);
                return;
            }
            for (int i = start;
                i < candidates.size() && target - candidates[i] >= 0; i++) {
                path.push_back(candidates[i]);
                DFS(i, target - candidates[i]);
                path.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
            std::sort(candidates.begin(), candidates.end());
            this->candidates = candidates;
            DFS(0, target);

            return res;
        }

    };

}

int test_p39_combinationSum() {
    using namespace p39;

    vector<int> nums;
    int target;
    vector<vector<int>> res;

    nums = { 2,3,6,7 };
    target = 7;
    res = Solution().combinationSum(nums, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    nums = { 2,3,5 };
    target = 8;
    res = Solution().combinationSum(nums, target);
    for (auto it : res) {
        println(it.begin(), it.end());
    }

    return 0;
}
