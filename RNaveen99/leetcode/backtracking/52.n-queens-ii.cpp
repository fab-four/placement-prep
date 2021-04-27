/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/n-queens-ii/
 */

class Solution {
    int count = 0;
    vector<bool> colTracker;
    // Dale diagonal = row - column = const
    vector<bool> leftDiagonal;
    // Hill diagonal = row + column = const
    vector<bool> rightDiagonal;

  public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        colTracker = vector<bool>(n, false);
        leftDiagonal = vector<bool>(2 * n - 1, false);
        rightDiagonal = vector<bool>(2 * n - 1, false);

        solveNQueensUtil(board, 0);
        return count;
    }

    void solveNQueensUtil(vector<string> &board, int row) {
        if (row == board.size()) {
            count++;
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