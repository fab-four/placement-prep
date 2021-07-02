/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/max-area-of-island/
 */

// similar to LC - 200. number of islands
class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j, rows, cols));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, const int &rows, const int &cols) {
        if (i < 0 || i == rows || j < 0 || j == cols || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = 2;
        return 1 + dfs(grid, i + 1, j, rows, cols) + dfs(grid, i - 1, j, rows, cols) +
               dfs(grid, i, j + 1, rows, cols) + dfs(grid, i, j - 1, rows, cols);
    }
};