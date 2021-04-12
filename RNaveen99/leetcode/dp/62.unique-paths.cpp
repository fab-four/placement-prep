/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/unique-paths/
 */

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }

        return matrix[m - 1][n - 1];
    }
};

class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                row[j] = row[j - 1] + row[j];
            }
        }

        return row[n - 1];
    }
};