// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/unique-paths-ii/

array<int, 4> dx = {1, 0};
array<int, 4> dy = {0, 1};

class Solution {
public:
  // Time Complexity : O(n^2)
  // Space Complexity : O(n^2)
  int uniquePathsWithObstacles(vector<vector<int>> &grid) {
    auto rows = grid.size();
    if (rows == 0) {
      return 0;
    }
    auto cols = grid[0].size();
    if (grid[rows - 1][cols - 1]) {
      return 0;
    }
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
      if (grid[i][0]) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 0; i < cols; i++) {
      if (grid[0][i]) {
        break;
      }
      dp[0][i] = 1;
    }
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (grid[i][j]) {
          continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[rows - 1][cols - 1];
    // return dfs(obstacleGrid, 0, 0);
  }

  int dfs(vector<vector<int>> &grid, int cr, int cc) {
    if (isOutOfBounds(cr, cc, grid.size(), grid[0].size()) || grid[cr][cc]) {
      return 0;
    }
    if ((cr == grid.size() - 1) && (cc == grid[0].size() - 1)) {
      return 1;
    }
    grid[cr][cc] = 1;
    int res = 0;
    for (int i = 0; i < dx.size(); i++) {
      res += dfs(grid, cr + dx[i], cc + dy[i]);
    }
    grid[cr][cc] = 0;
    return res;
  }

  bool isOutOfBounds(int cr, int cc, int rows, int cols) {
    return (cr < 0) || (cc < 0) || (cr >= rows) || (cc >= cols);
  }
};
