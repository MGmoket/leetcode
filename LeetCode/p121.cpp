﻿/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;
namespace p121 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() < 2) return 0;
            int curProfit = 0;
            int buyInPrice = prices[0];
            int minPrice = buyInPrice;

            for (size_t i = 1; i < prices.size(); ++i) {
                int curPrice = prices[i];
                
                if (curPrice >= minPrice + curProfit) {
                    curProfit = curPrice - minPrice;
                    buyInPrice = minPrice;
                }
                else {
                    if (curPrice < minPrice) minPrice = curPrice;
                }
            }
            return curProfit;
        }
    };
}

int test_p121_maxProfit() {
    using namespace p121;

    vector<int> prices;
    prices = { 7,1,5,3,6,4 };
    cout << "max profit: " << Solution().maxProfit(prices) << endl;
    prices = { 7,2,5,3,1,4 };
    cout << "max profit: " << Solution().maxProfit(prices) << endl;

    return 0;
}
