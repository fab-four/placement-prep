/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int profit = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // sell stock: max(previous profit, selling stock at current price)
            profit = max(profit, hold + prices[i] - fee);
            // buy stock: max(stock at previous price, stock at current price)
            hold = max(hold, profit - prices[i]);
        }
        return profit;
    }
};