// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/flood-fill/

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int new_color) {
    vector<vector<int>> result(image);
    vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size()));
    dfs(image, sr, sc, new_color, image[sr][sc], result, vis);
    return result;
  }

  void dfs(const vector<vector<int>> &image, int cr, int cc, int new_color,
           int src_color, vector<vector<int>> &result,
           vector<vector<bool>> &vis) {
    if (isOutOfBounds(cr, cc, image.size(), image[0].size()) || vis[cr][cc] ||
        image[cr][cc] != src_color) {
      return;
    }
    vis[cr][cc] = true;
    result[cr][cc] = new_color;
    // U, D, R, L
    array<int, 4> dx = {-1, 1, 0, 0};
    array<int, 4> dy = {0, 0, 1, -1};
    for (int i = 0; i < dx.size(); i++) {
      dfs(image, cr + dx[i], cc + dy[i], new_color, src_color, result, vis);
    }
    vis[cr][cc] = false;
  }

  bool isOutOfBounds(int cr, int cc, int rows, int cols) {
    return (cr < 0) || (cc < 0) || (cr >= rows) || (cc >= cols);
  }
};
