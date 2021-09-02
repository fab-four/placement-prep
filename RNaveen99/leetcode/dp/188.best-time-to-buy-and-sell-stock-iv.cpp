/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

// Note: at most K-transactions

// row = transaction number
// col = day
// dp[transaction][day] = max {First, Second}
// First : don't perform transaction today .... i.e. use previous day value
//  => dp[transaction][day-1]

// Second : perform transaction today .... i.e sell today
//  => max(price[today] - price[j] + dp[transaction - 1][j]) where 0 <= j < today

class Solution {
    vector<vector<int>> dp;

  public:
    int maxProfit(int k, vector<int> &prices) {
        int size = prices.size();
        if (size <= 1)
            return 0;
        dp.resize(k + 1, vector<int>(size, 0));

        for (int r = 1; r <= k; r++) {
            for (int c = 1; c < size; c++) {
                dp[r][c] = max(dp[r][c - 1], findMax(r, c, prices));
            }
        }
        return dp[k][size - 1];
    }
    int findMax(int r, int c, vector<int> &prices) {
        int maxValue = 0;
        for (int j = 0; j < c; j++) {
            maxValue = max(maxValue, prices[c] - prices[j] + dp[r - 1][j]);
        }
        return maxValue;
    }
};

// state based explaination
// Reference : https://www.youtube.com/watch?v=6928FkPhGUA

// even Index = hold / buy
// odd Index = hold / sell

class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        int totalTransactions = 2 * k;
        if (totalTransactions == 0)
            return 0;
        vector<int> dp(totalTransactions, 0);
        for (int i = 0; i < totalTransactions; i += 2) {
            dp[i] = INT_MIN;
        }

        for (int price : prices) {
            for (int i = 0; i < totalTransactions; i++) {
                if (i == 0) {
                    dp[i] = max(dp[i], -price);
                } else if (i % 2 == 0) {
                    dp[i] = max(dp[i], dp[i - 1] - price);
                } else {
                    dp[i] = max(dp[i], dp[i - 1] + price);
                }
            }
        }
        return dp[totalTransactions - 1];
    }
};