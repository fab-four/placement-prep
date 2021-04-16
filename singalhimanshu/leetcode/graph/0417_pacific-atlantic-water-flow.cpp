// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/pacific-atlantic-water-flow

constexpr array<int, 4> dx = {1, -1, 0, 0};
constexpr array<int, 4> dy = {0, 0, 1, -1};

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    vector<vector<bool>> pacific(heights.size(),
                                 vector<bool>(heights[0].size()));
    vector<vector<bool>> atlantic(heights.size(),
                                  vector<bool>(heights[0].size()));
    // Top and bottom row
    for (int c = 0; c < heights[0].size(); c++) {
      dfs(0, c, heights, pacific, 0);
      dfs(heights.size() - 1, c, heights, atlantic, 0);
    }
    // Left and right col
    for (int r = 0; r < heights.size(); r++) {
      dfs(r, 0, heights, pacific, 0);
      dfs(r, heights[0].size() - 1, heights, atlantic, 0);
    }
    vector<vector<int>> res;
    for (int r = 0; r < heights.size(); r++) {
      for (int c = 0; c < heights[0].size(); c++) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }
    return res;
  }

  void dfs(int cr, int cc, const vector<vector<int>> &heights,
           vector<vector<bool>> &ocean, int prev_height) {
    if (isOutOfBounds(cr, cc, heights.size(), heights[0].size())) {
      return;
    }
    if (heights[cr][cc] < prev_height) {
      return;
    }
    if (ocean[cr][cc]) {
      return;
    }
    ocean[cr][cc] = true;
    for (int i = 0; i < dx.size(); i++) {
      dfs(cr + dx[i], cc + dy[i], heights, ocean, heights[cr][cc]);
    }
  }

  bool isOutOfBounds(int r, int c, int rows, int cols) {
    return (r < 0) || (c < 0) || (r >= rows) || (c >= cols);
  }
};
