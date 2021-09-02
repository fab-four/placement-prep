/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/rotting-oranges/
 */

class Solution {
    vector<vector<int>> minTime;
    vector<int> directions = {0, 1, 0, -1, 0};

  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        minTime.resize(rows, vector<int>(cols, INT_MAX));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    bfs(grid, r, c, rows, cols);
                }
            }
        }
        int time = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    if (minTime[r][c] == INT_MAX) {
                        return -1;
                    } else {
                        time = max(time, minTime[r][c]);
                    }
                }
            }
        }
        return time;
    }
    void bfs(vector<vector<int>> &grid, int r, int c, const int &rows, const int &cols) {
        queue<pair<int, int>> q;
        q.push({r, c});

        minTime[r][c] = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i + 1 < directions.size(); i++) {
                    int x = r + directions[i];
                    int y = c + directions[i + 1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 &&
                        minTime[x][y] > minTime[r][c] + 1) {
                        minTime[x][y] = minTime[r][c] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
};