/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sort-the-matrix-diagonally/
 */

class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        // diagonalID, minHeap
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> m;
        int rows = mat.size();
        int cols = mat[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                m[r - c].emplace(mat[r][c]);
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                mat[r][c] = m[r - c].top();
                m[r - c].pop();
            }
        }
        return mat;
    }
};

class Solution {
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int maxLengthOfDiagonal = min(mat.size(), mat[0].size());
        for (int d = 0; d + 1 < maxLengthOfDiagonal; d++) {
            for (int r = 0; r + 1 < mat.size(); r++) {
                for (int c = 0; c + 1 < mat[0].size(); c++) {
                    if (mat[r][c] > mat[r + 1][c + 1]) {
                        swap(mat[r][c], mat[r + 1][c + 1]);
                    }
                }
            }
        }
        return mat;
    }
};