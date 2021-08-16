// Link: https://leetcode.com/problems/unique-paths/

class Solution {
public:
  // Time Complexity: O(n * m)
  // Space Complexity: O(n * m)
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp.back().back();
  }
};
