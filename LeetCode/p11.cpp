
/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace p11 {


class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        
        for (size_t i = 0; i < height.size()-1; ++i) {
            for (size_t j = i; j < height.size(); ++j) {
                int len = j - i;
                int mi = __min(height.at(i), height.at(j)) * len;
                if (mx < mi) mx = mi;
            }
        }
        return mx;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};

}

int test_p11_maxArea() {
    using namespace p11;
    vector<int> heights = { 1,8,6,2,5,4,8,3,7};
    int area = Solution2().maxArea(heights);
    cout << area << endl;

    return 0;
}
