/*
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

Example:

Input: 4
Output: false
Explanation: If there are 4 stones in the heap, then you will never win the game;
             No matter 1, 2, or 3 stones you remove, the last stone will always be
             removed by your friend.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/nim-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>

using namespace std;

namespace p292 {
    class Solution0 {
    public:
        bool canWinNim(int n) {
            if (n <= 3) return true;
            bool b1 = true;
            bool b2 = true;
            bool b3 = true;
            bool b = false;
            for (int i = 4; i <= n; ++i) {
                b = !(b1 && b2 && b3);
                b1 = b2;
                b2 = b3;
                b3 = b;
            }
            return b;
        }
    };

    class Solution {
    public:
        bool canWinNim(int n) {
            return n % 4 != 0;
        }
    };
}


int test_p292_canWinNim() {
    using namespace p292;
    int n;

    // 通过这里的规律确定，如果是4的倍数，就会输。
    for (int i = 1; i < 100; ++i) {
        if (!Solution().canWinNim(i)) {
            cout << i << " can't win\n";
        }
    }


    n = 4;
    cout << n << " canWin? " << Solution().canWinNim(n) << endl;

    n = 1199886170;
    cout << n << " canWin? " << Solution().canWinNim(n) << endl;


    return 0;
}
