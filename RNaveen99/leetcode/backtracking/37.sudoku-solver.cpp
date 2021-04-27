/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sudoku-solver/
 */

class Solution {
    vector<vector<bool>> rowTracker;
    vector<vector<bool>> colTracker;
    vector<vector<bool>> boxTracker;

  public:
    void solveSudoku(vector<vector<char>> &board) {
        int size = board.size();
        rowTracker = vector<vector<bool>>(size, vector<bool>(size, false));
        colTracker = vector<vector<bool>>(size, vector<bool>(size, false));
        boxTracker = vector<vector<bool>>(size, vector<bool>(size, false));
        initialConfiguration(board);
        backtrack(board, 0, 0);
    }
    bool backtrack(vector<vector<char>> &board, int row, int col) {
        if (row == board.size()) {
            return true;
        }
        if (col == board.size()) {
            return backtrack(board, row + 1, 0);
        }
        if (board[row][col] != '.') {
            return backtrack(board, row, col + 1);
        }
        for (char d = '1'; d <= '9'; ++d) {
            if (isSafe(board, row, col, d)) {
                placeNumber(board, row, col, d);
                if (backtrack(board, row, col + 1)) {
                    return true;
                }
                removeNumber(board, row, col, d);
            }
        }
        return false;
    }
    void initialConfiguration(vector<vector<char>> &board) {
        int size = board.size();
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (board[row][col] != '.') {
                    placeNumber(board, row, col, board[row][col]);
                }
            }
        }
    }
    void placeNumber(vector<vector<char>> &board, int row, int col, char val) {
        board[row][col] = val;
        rowTracker[row][val - '1'] = true;
        colTracker[col][val - '1'] = true;
        boxTracker[((row / 3) * 3) + (col / 3)][val - '1'] = true;
    }
    void removeNumber(vector<vector<char>> &board, int row, int col, char val) {
        board[row][col] = '.';
        rowTracker[row][val - '1'] = false;
        colTracker[col][val - '1'] = false;
        boxTracker[((row / 3) * 3) + (col / 3)][val - '1'] = false;
    }

    bool isSafe(vector<vector<char>> &board, int row, int col, char val) {
        return !(rowTracker[row][val - '1'] || colTracker[col][val - '1'] ||
                 boxTracker[((row / 3) * 3) + (col / 3)][val - '1']);
    }
};

class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) { backtrack(board, 0, 0); }

    bool backtrack(vector<vector<char>> &board, int row, int col) {
        for (int i = row; i < 9; i++, col = 0) { // note: must reset col here!
            for (int j = col; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (backtrack(board, i, j + 1))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char num) {
        int blkrow = (row / 3) * 3, blkcol = (col / 3) * 3; // Block no. is i/3, first element is i/3*3
        for (int i = 0; i < 9; i++)
            if (board[i][col] == num || board[row][i] == num || board[blkrow + i / 3][blkcol + i % 3] == num)
                return false;
        return true;
    }
};