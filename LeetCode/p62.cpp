/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/unique-paths
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

#include <iostream>
#include <algorithm>

using namespace std;

namespace p62 {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            if (m == 0 || n == 0) return -1;

            double devidend = 1;
            double devisor = 1;
            int c = m + n - 2;
            int k = min(n, m) - 1;
            int s = k;
            for (int i = 0; i < k; ++i) {
                devidend *= c--;
                devisor *= s--;
            }

            return ceil(devidend / devisor);

        }
    };


    class Solution2 { // ��̬�滮����
    public:
        int uniquePaths(int m, int n) {
            int a[101][101] = { 0 };
            for (int i = 0; i < m; i++) a[i][0] = 1;
            for (int j = 0; j < n; j++) a[0][j] = 1;
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    a[i][j] = a[i - 1][j] + a[i][j - 1];
                }
            }
            return a[m - 1][n - 1];
        }
    };
}

int test_p62_uniquePaths() {
    using namespace p62;
    int m, n;

    m = 3;
    n = 2;
    cout << "m=" << m << ",n=" << n << ", paths:" << Solution().uniquePaths(m, n) << endl;

    m = 10;
    n = 10;
    cout << "m=" << m << ",n=" << n << ", paths:" << Solution2().uniquePaths(m, n) << endl;

    return 0;
}
