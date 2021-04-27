/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/n-queens/
 */

class Solution {
    vector<vector<string>> results;

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solveNQueensUtil(board, 0);
        return results;
    }

    void solveNQueensUtil(vector<string> &board, int row) {
        if (row == board.size()) {
            results.emplace_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                solveNQueensUtil(board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string> &board, int row, int col) {
        int size = board.size();
        // check col
        for (int i = 0; i < size; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // check upper left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }
        // check upper right diagonal
        r = row, c = col;
        while (r >= 0 && c < size) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
};

class Solution {
    vector<vector<string>> results;
    vector<bool> colTracker;
    // Dale diagonal = row - column = const
    vector<bool> leftDiagonal;
    // Hill diagonal = row + column = const
    vector<bool> rightDiagonal;

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        colTracker = vector<bool>(n, false);
        leftDiagonal = vector<bool>(2 * n - 1, false);
        rightDiagonal = vector<bool>(2 * n - 1, false);

        solveNQueensUtil(board, 0);
        return results;
    }

    void solveNQueensUtil(vector<string> &board, int row) {
        if (row == board.size()) {
            results.emplace_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                placeRemoveQueen(board, row, col, true);
                solveNQueensUtil(board, row + 1);
                placeRemoveQueen(board, row, col, false);
            }
        }
    }

    bool isSafe(vector<string> &board, int row, int col) {
        int size = board.size();
        bool flag = colTracker[col] || leftDiagonal[row - col + size - 1] || rightDiagonal[row + col];

        return !flag;
    }

    void placeRemoveQueen(vector<string> &board, int row, int col, bool place) {
        if (place) {
            board[row][col] = 'Q';
            colTracker[col] = leftDiagonal[row - col + board.size() - 1] = rightDiagonal[row + col] = true;
        } else {
            board[row][col] = '.';
            colTracker[col] = leftDiagonal[row - col + board.size() - 1] = rightDiagonal[row + col] = false;
        }
    }
};