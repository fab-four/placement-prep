// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/coin-change/

class Solution {
public:
  // Time Complexity : O(n^2)
  // Space Complexity : O(n)
  int coinChange(vector<int> &coins, int amount) {
    int mmax = amount + 1;
    sort(begin(coins), end(coins));
    vector<int> dp(amount + 1, mmax);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (i < coins[j]) {
          break;
        }
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
};
