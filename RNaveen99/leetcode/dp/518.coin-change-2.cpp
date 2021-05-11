/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/coin-change-2/
 */

class Solution {
  public:
    int change(int target, vector<int> &coins) {
        vector<int> A(target + 1, 0);
        // base case : # combinations to get target == 0 is 1 i.e. choose no coin.
        A[0] = 1;
        for (int coinValue : coins) {
            for (int amount = coinValue; amount <= target; amount++) {
                A[amount] += A[amount - coinValue];
            }
        }
        return A[target];
    }
};