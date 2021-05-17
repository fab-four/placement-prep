/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/01-matrix/
 */

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 0) {
                    q.push({r, c});
                    distance[r][c] = 0;
                }
            }
        }
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto &d : directions) {
                int x = r + d[0];
                int y = c + d[1];
                if (isvalid(x, y, rows, cols) && distance[x][y] == -1) {
                    distance[x][y] = distance[r][c] + 1;
                    q.push({x, y});
                }
            }
        }
        return distance;
    }

    bool isvalid(int x, int y, int rows, int cols) {
        if (x == rows || y == cols || x < 0 || y < 0)
            return false;
        return true;
    }
};

class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto &d : directions) {
                int x = r + d[0];
                int y = c + d[1];
                if (isvalid(x, y, rows, cols) && visited[x][y] == false) {
                    mat[x][y] = mat[r][c] + 1;
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return mat;
    }

    bool isvalid(int x, int y, int rows, int cols) {
        if (x == rows || y == cols || x < 0 || y < 0)
            return false;
        return true;
    }
};