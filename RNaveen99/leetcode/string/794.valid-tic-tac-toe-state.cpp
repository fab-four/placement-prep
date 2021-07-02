/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/valid-tic-tac-toe-state/
 */

class Solution {
    vector<vector<vector<int>>> winningCases = {
        // rows
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        // cols
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        // diagonals
        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}}};

  public:
    bool validTicTacToe(vector<string> &board) {
        int countX = 0;
        int countO = 0;
        int countSpace = 0;
        for (string row : board) {
            for (char c : row) {
                if (c == 'X') {
                    countX++;
                } else if (c == 'O') {
                    countO++;
                } else {
                    countSpace++;
                }
            }
        }
        int diff = countX - countO;
        bool X = isWinner(board, 'X');
        bool O = isWinner(board, 'O');

        if (diff == 1) {
            if (O) {
                return false;
            }
            return true;
        }
        if (diff == 0) {
            if (X)
                return false;
            return true;
        }
        return false;
    }
    bool isWinner(vector<string> &board, char ch) {
        for (auto c : winningCases) {
            if ((board[c[0][0]][c[0][1]] == board[c[1][0]][c[1][1]]) &&
                (board[c[1][0]][c[1][1]] == board[c[2][0]][c[2][1]]) && (board[c[0][0]][c[0][1]] == ch)) {
                return true;
            }
        }
        return false;
    }
};