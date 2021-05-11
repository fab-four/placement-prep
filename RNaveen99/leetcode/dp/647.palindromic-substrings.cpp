/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/palindromic-substrings/
 */

class Solution {
  public:
    int countSubstrings(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        int count = 0;
        for (int gap = 0; gap < size; gap++) {
            for (int i = 0, j = gap; j < size; i++, j++) {
                if (gap == 0) {
                    // substring of length 1
                    dp[i][j] = true;
                } else if (gap == 1) {
                    // substring of length 2
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                } else {
                    if ((s[i] == s[j]) && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};