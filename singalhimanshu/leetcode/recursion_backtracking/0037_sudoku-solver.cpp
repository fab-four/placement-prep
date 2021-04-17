// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    int n = board.size();
    solve(n, board);
  }

  bool solve(int n, vector<vector<char>> &board) {
    int cr = 0, cc = 0;
    if (!firstEmpty(cr, cc, n, board)) {
      return true;
    }
    for (int val = 1; val <= n; val++) {
      if (isSafe(cr, cc, val + '0', n, board)) {
        board[cr][cc] = val + '0';
        if (solve(n, board)) {
          return true;
        }
        board[cr][cc] = '.';
      }
    }
    return false;
  }

  bool firstEmpty(int &cr, int &cc, int n, const vector<vector<char>> &board) {
    for (cr = 0; cr < n; cr++) {
      for (cc = 0; cc < n; cc++) {
        if (board[cr][cc] == '.') {
          return true;
        }
      }
    }
    return false;
  }

  bool isSafe(int cr, int cc, char val, int n,
              const vector<vector<char>> &board) {
    // check current row and col
    for (int i = 0; i < n; i++) {
      if (board[i][cc] == val || board[cr][i] == val) {
        return false;
      }
    }
    int grid_size = sqrt(n);
    int sub_grid_start_r = cr - (cr % grid_size);
    int sub_grid_start_c = cc - (cc % grid_size);
    // check current grid
    for (int i = 0; i < grid_size; i++) {
      for (int j = 0; j < grid_size; j++) {
        if (board[i + sub_grid_start_r][j + sub_grid_start_c] == val) {
          return false;
        }
      }
    }
    return true;
  }
};
