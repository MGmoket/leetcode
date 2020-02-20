/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
#include <iostream>
#include <string>
#include "myprint"
using namespace std;

namespace p79 {

    class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            if (board.size() == 0) return false;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool dfs(vector<vector<char>>& board, string& word, int i, int j, int length) {
            if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || length >= word.size() || word[length] != board[i][j]) {
                return false;
            }
            if (length == word.size() - 1 && word[length] == board[i][j]) {
                return true;
            }
            char temp = board[i][j];
            board[i][j] = '0';
            bool flag = dfs(board, word, i, j + 1, length + 1) || dfs(board, word, i, j - 1, length + 1) || dfs(board, word, i + 1, j, length + 1) || dfs(board, word, i - 1, j, length + 1);
            board[i][j] = temp;
            return flag;
        }
    };


}


int test_p79_exist() {
    using namespace p79;
    vector<vector<char>> board;
    string word;

    board = {
  {'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}
    };
    word = "ABCCED";
    cout << Solution().exist(board, word) << endl;

    word = "SEE";
    cout << Solution().exist(board, word) << endl;

    word = "ABCB";
    cout << Solution().exist(board, word) << endl;

    return 0;
}

