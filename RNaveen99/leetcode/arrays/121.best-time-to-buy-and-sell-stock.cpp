/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};