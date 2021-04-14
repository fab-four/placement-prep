// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/number-of-islands/

constexpr array<int, 4> dx = {1, -1, 0, 0};
constexpr array<int, 4> dy = {0, 0, 1, -1};

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    int count = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[0].size(); j++) {
        if (!vis[i][j] && grid[i][j] == '1') {
          dfs(i, j, grid, vis);
          count++;
        }
      }
    }
    return count;
  }

  void dfs(int cr, int cc, const vector<vector<char>> &grid,
           vector<vector<bool>> &vis) {
    if (isOutOfBounds(cr, cc, grid.size(), grid[0].size()) ||
        grid[cr][cc] == '0' || vis[cr][cc]) {
      return;
    }
    vis[cr][cc] = true;
    for (size_t i = 0; i < dx.size(); i++) {
      int new_cr = cr + dx[i];
      int new_cc = cc + dy[i];
      dfs(new_cr, new_cc, grid, vis);
    }
  }

  bool isOutOfBounds(int r, int c, int rows, int cols) {
    return (r < 0) || (c < 0) || (r >= rows) || (c >= cols);
  }
};
