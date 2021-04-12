// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
public:
  vector<string> findPath(vector<vector<int>> &m, int n) {
    if (m[0][0] == 0 && m[n - 1][n - 1] == 0) {
      return {};
    }
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<string> result;
    dfs(0, 0, "", m, vis, result);
    sort(begin(result), end(result));
    return result;
  }

  void dfs(int row, int col, string path, const vector<vector<int>> &m,
           vector<vector<bool>> &vis, vector<string> &result) {
    if (isOutOfBounds(row, col, m.size()) || vis[row][col] ||
        m[row][col] == 0) {
      return;
    }
    int n = m.size();
    if ((row == n - 1) && (col == n - 1)) {
      result.emplace_back(path);
      return;
    }
    vis[row][col] = true;
    dfs(row - 1, col, path + "U", m, vis, result);
    dfs(row + 1, col, path + "D", m, vis, result);
    dfs(row, col - 1, path + "L", m, vis, result);
    dfs(row, col + 1, path + "R", m, vis, result);
    vis[row][col] = false;
  }

  bool isOutOfBounds(int row, int col, int n) {
    return (row < 0) || (col < 0) || (row >= n) || (col >= n);
  }
};
