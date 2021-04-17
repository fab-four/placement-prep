// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/n-queens/

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, res);
    return res;
  }

  void solve(int row, int n, vector<string> &board,
             vector<vector<string>> &res) {
    if (row == n) {
      res.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isSafe(row, col, n, board)) {
        board[row][col] = 'Q';
        solve(row + 1, n, board, res);
        board[row][col] = '.';
      }
    }
  }

  bool isSafe(int row, int col, int n, const vector<string> &board) {
    // Check column
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q') {
        return false;
      }
    }
    // cur to (0, 0)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    // cur to (0, n)
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
