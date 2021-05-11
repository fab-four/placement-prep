/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/coin-change/
 */

class Solution {
  public:
    int coinChange(vector<int> &coins, int target) {
        vector<int> A(target + 1, target + 1);
        // base case : # coins to get target == 0 is 0 i.e. choose no coin.
        A[0] = 0;
        for (int coinValue : coins) {
            for (int amount = coinValue; amount <= target; amount++) {
                A[amount] = min(A[amount], A[amount - coinValue] + 1);
            }
        }
        return A[target] > target ? -1 : A[target];
    }
};

class Solution {
  public:
    int coinChange(vector<int> &coins, int target) {
        int Max = target + 1;
        vector<int> dp(target + 1, Max);
        // base case : # coins to get target == 0 is 0 i.e. choose no coin.
        dp[0] = 0;
        for (int amount = 1; amount <= target; amount++) {
            for (int coinValue : coins) {
                if (amount >= coinValue) {
                    dp[amount] = min(dp[amount], dp[amount - coinValue] + 1);
                }
            }
        }
        return dp[target] > target ? -1 : dp[target];
    }
};
