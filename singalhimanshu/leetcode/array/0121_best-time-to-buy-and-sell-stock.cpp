// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int cur_max_profit = 0;
    int max_profit = 0;
    for (size_t i = 1; i < prices.size(); i++) {
      cur_max_profit += prices[i] - prices[i - 1];
      cur_max_profit = max(0, cur_max_profit);
      max_profit = max(max_profit, cur_max_profit);
    }
    return max_profit;
  }
};
