/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int valley = prices[0];
        int peak = prices[0];
        int maxProfit = 0;
        int size = prices.size();
        int i = 0;
        while (i < size - 1) {
            // find minimum valley in consecutive valleys
            while (i < size - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            valley = prices[i];
            // find maximum peak in consecutive peaks
            while (i < size - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            peak = prices[i];
            int profit = peak - valley;
            maxProfit += profit;
        }
        return maxProfit;
    }
};

// its an increasing decreasing array ... sum all increasing difference
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};