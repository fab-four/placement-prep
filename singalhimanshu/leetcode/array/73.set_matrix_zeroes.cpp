// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/set-matrix-zeroes/
//
class Solution {
public:
  // Time Complexity: O(m * n)
  // Space Complexity: O(1)
  void setZeroes(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    assert(rows > 0);
    int cols = matrix[0].size();
    bool first_row = false;
    for (int i = 0; i < cols; i++) {
      if (matrix[0][i] == 0) {
        first_row = true;
        break;
      }
    }
    bool first_col = false;
    for (int r = 0; r < rows; r++) {
      if (matrix[r][0] == 0) {
        first_col = true;
        break;
      }
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r][c] == 0) {
          matrix[r][0] = 0;
          matrix[0][c] = 0;
        }
      }
    }
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
    }
    if (first_row) {
      for (int c = 0; c < cols; c++) {
        matrix[0][c] = 0;
      }
    }
    if (first_col) {
      for (int r = 0; r < rows; r++) {
        matrix[r][0] = 0;
      }
    }
  }
};
