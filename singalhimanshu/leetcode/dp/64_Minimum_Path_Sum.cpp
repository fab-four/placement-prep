class Solution {
public:
  // Time Complexity: O(n^2)
  // Space Complexity: O(n^2)
  int minPathSum(vector<vector<int>> &grid) {
    int rows = grid.size();
    assert(rows > 0);
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = grid[0][0];
    for (int r = 1; r < rows; r++) {
      dp[r][0] = dp[r - 1][0] + grid[r][0];
    }
    for (int c = 1; c < cols; c++) {
      dp[0][c] = dp[0][c - 1] + grid[0][c];
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        dp[r][c] = grid[r][c] + min(dp[r - 1][c], dp[r][c - 1]);
      }
    }
    return dp.back().back();
  }
};
