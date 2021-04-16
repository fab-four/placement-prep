/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/counting-bits/
 */

class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 0; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};