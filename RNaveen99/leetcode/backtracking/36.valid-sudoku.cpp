/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/valid-sudoku/
 */

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int size = board.size();
        vector<vector<bool>> rowMap(size, vector<bool>(size, false));
        vector<vector<bool>> colMap(size, vector<bool>(size, false));
        vector<vector<bool>> boxMap(size, vector<bool>(size, false));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != '.') {
                    int cellValue = board[i][j] - '0';
                    if (rowMap[i][cellValue - 1]) {
                        return false;
                    } else {
                        rowMap[i][cellValue - 1] = true;
                    }
                    if (colMap[j][cellValue - 1]) {
                        return false;
                    } else {
                        colMap[j][cellValue - 1] = true;
                    }
                    int box = (i / 3) * 3 + j / 3;
                    if (boxMap[box][cellValue - 1]) {
                        return false;
                    } else {
                        boxMap[box][cellValue - 1] = true;
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int size = board.size();
        vector<vector<char>> rowMap(size, vector<char>(size, '.'));
        vector<vector<char>> colMap(size, vector<char>(size, '.'));
        vector<vector<char>> boxMap(size, vector<char>(size, '.'));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] != '.') {
                    int cellValue = board[i][j] - '0';
                    if (rowMap[i][cellValue - 1] == board[i][j]) {
                        return false;
                    } else {
                        rowMap[i][cellValue - 1] = board[i][j];
                    }
                    if (colMap[j][cellValue - 1] == board[i][j]) {
                        return false;
                    } else {
                        colMap[j][cellValue - 1] = board[i][j];
                    }
                    int box = (i / 3) * 3 + j / 3;
                    if (boxMap[box][cellValue - 1] == board[i][j]) {
                        return false;
                    } else {
                        boxMap[box][cellValue - 1] = board[i][j];
                    }
                }
            }
        }
        return true;
    }
};

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> rowMap(9, vector<int>(9, 0));
        vector<vector<int>> columnMap(9, vector<int>(9, 0));
        vector<vector<int>> boxMap(9, vector<int>(9, 0));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.')
                    continue;
                int cellValue = board[i][j] - '0';
                if (++rowMap[i][cellValue - 1] > 1)
                    return false;
                if (++columnMap[j][cellValue - 1] > 1)
                    return false;
                int box = (i / 3) * 3 + (j / 3);
                if (++boxMap[box][cellValue - 1] > 1)
                    return false;
            }
        }
        return true;
    }
};