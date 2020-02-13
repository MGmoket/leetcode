
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotate-image
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <iostream>
#include <vector>
#include "myprint"
using namespace std;

namespace p48 {

}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //���ùٷ�����ת�ã��ٻ��е�������
        int i, j, tmp;
        int length = matrix[0].size();
        //ת��
        for (i = 0; i < length - 1; i++) {
            for (j = i + 1; j < length; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        //����
        for (i = 0; i < length; i++) {
            for (j = 0; j < length / 2; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][length - 1 - j];
                matrix[i][length - 1 - j] = tmp;
            }
        }
    }
};


int test_p48_rotate() {
    using namespace p48;
    
    vector<vector<int>> matrix;

    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution().rotate(matrix);

    for (auto it : matrix) {
        println(it.begin(), it.end());
    }

    return 0;
}
