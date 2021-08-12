class Solution {
public:
  // Time Complexity: O(n^2)
  // Space Complexity: O(n^2)
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int row_start = 0, col_start = 0;
    int row_end = n - 1, col_end = n - 1;
    int num = 1;
    while (row_start <= row_end && col_start <= col_end) {
      for (int c = col_start; c <= col_end; c++) {
        matrix[row_start][c] = num++;
      }
      row_start++;
      for (int r = row_start; r <= row_end; r++) {
        matrix[r][col_end] = num++;
      }
      col_end--;
      for (int c = col_end; c >= col_start; c--) {
        matrix[row_end][c] = num++;
      }
      row_end--;
      for (int r = row_end; r >= row_start; r--) {
        matrix[r][col_start] = num++;
      }
      col_start++;
    }
    return matrix;
  }
};
