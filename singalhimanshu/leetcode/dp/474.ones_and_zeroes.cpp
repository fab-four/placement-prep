// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
  // Time Complexity : O(strs.size() * m * n)
  // Space Complexity : O(m * n)
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const auto &str : strs) {
      int zero_count = count(begin(str), end(str), '0');
      int ones_count = count(begin(str), end(str), '1');
      for (int i = m; i >= zero_count; i--) {
        for (int j = n; j >= ones_count; j--) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - zero_count][j - ones_count]);
        }
      }
    }
    return dp[m][n];
  }
};
