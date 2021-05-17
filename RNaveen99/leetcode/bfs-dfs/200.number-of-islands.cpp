/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-islands/
 */

class Solution {
  public:
    int numIslands(vector<vector<char>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    mergeLands(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void mergeLands(vector<vector<char>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '#';
        mergeLands(grid, r, c + 1);
        mergeLands(grid, r, c - 1);
        mergeLands(grid, r + 1, c);
        mergeLands(grid, r - 1, c);
    }
};