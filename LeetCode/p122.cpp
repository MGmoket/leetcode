﻿/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "myprint"

using namespace std;

namespace p122 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;

            int start = 0;
            for (size_t i = 1; i < prices.size(); ++i) {
                if (prices[i] <= prices[i - 1]) {
                    profit += prices[i - 1] - prices[start];
                    start = i;
                }
            }

            if (prices.back() > prices[start]) profit += prices.back() - prices[start];

            return profit;
        }
    };

    class Solution2 {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            for (size_t i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

    };
}

int test_p122_maxProfit() {

    using namespace p122;
    vector<int> prices;

    prices = { 7,1,5,3,6,4 };
    cout << Solution2().maxProfit(prices) << endl;

    prices = { 1,2,3,4,5 };
    cout << Solution2().maxProfit(prices) << endl;

    prices = { 7,6,4,3,1 };
    cout << Solution2().maxProfit(prices) << endl;
    return 0;
}