/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);

        // Rest state: At the start, you don't have any stock if you just rest.
        s0[0] = 0;
        // Buy state : After buy, you should have -prices[0] profit.
        s1[0] = -prices[0];
        // sell state : can't, sell before buy so you should have 0 profit
        s2[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            // rest state[i] : max(rest state[i-1], sell state[i-1])
            s0[i] = max(s0[i - 1], s2[i - 1]);
            // buy state[i] : max(buy state[i-1], rest state[i-1] - buying i'th stock)
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            // sell state[i] : buy state[i-1] + selling i'th stock
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[prices.size() - 1], s2[prices.size() - 1]);
    }
};

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int s0 = 0;
        int s1 = -prices[0];
        int s2 = 0;

        int prev_s0 = s0;
        int prev_s1 = s1;
        int prev_s2 = s2;

        for (int i = 1; i < prices.size(); ++i) {
            s0 = max(prev_s0, prev_s2);
            s1 = max(prev_s1, prev_s0 - prices[i]);
            s2 = max(prev_s1 + prices[i], s2);

            prev_s0 = s0;
            prev_s1 = s1;
            prev_s2 = s2;
        }
        return max(s0, s2);
    }
};