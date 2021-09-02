/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 */

class Solution {
    vector<vector<int>> cache;
    vector<int> directions = {0, 1, 0, -1, 0};

  public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        cache.resize(rows, vector<int>(cols, 0));
        int maxLength = 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int length = dfs(matrix, r, c, rows, cols);
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }

    int dfs(vector<vector<int>> &matrix, int r, int c, int rows, int cols) {
        if (cache[r][c] != 0)
            return cache[r][c];

        int maxLength = 1;
        for (int i = 0; i + 1 < directions.size(); i++) {
            int x = r + directions[i];
            int y = c + directions[i + 1];

            if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] <= matrix[r][c])
                continue;
            int length = 1 + dfs(matrix, x, y, rows, cols);
            maxLength = max(maxLength, length);
        }
        cache[r][c] = maxLength;
        return maxLength;
    }
};