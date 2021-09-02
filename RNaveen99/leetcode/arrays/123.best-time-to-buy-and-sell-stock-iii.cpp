/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

// oneBuy: keeps track of the lowest price.
// oneBuyOneSell: keeps track of the biggest profit we could get.
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int oneBuyOneSell = 0;
        int twoBuyTwoSell = 0;
        int oneBuy = INT_MAX;
        int twoBuy = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            int p = prices[i];
            oneBuy = min(oneBuy, p);
            oneBuyOneSell = max(oneBuyOneSell, p - oneBuy);

            // the price for 2nd buy would be stock price - profit from 1st sell
            twoBuy = min(twoBuy, p - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, p - twoBuy);
        }

        return twoBuyTwoSell;
    }
};