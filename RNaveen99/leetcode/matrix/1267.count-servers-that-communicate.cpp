/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/count-servers-that-communicate/
 */

class Solution {
  public:
    int countServers(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> computerInRow(rows, 0);
        vector<int> computerInColumn(cols, 0);

        int connectedComputers = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c]) {
                    connectedComputers++;
                    computerInRow[r]++;
                    computerInColumn[c]++;
                }
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] && computerInRow[r] == 1 && computerInColumn[c] == 1) {
                    connectedComputers--;
                }
            }
        }
        return connectedComputers;
    }
};