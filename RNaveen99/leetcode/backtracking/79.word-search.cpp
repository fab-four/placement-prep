/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-search/
 */

class Solution {
    vector<vector<bool>> visited;

  public:
    bool exist(vector<vector<char>> &board, string word) {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (existUtil(board, row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool existUtil(vector<vector<char>> &board, int row, int col, string &word, int index) {
        if (index >= word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col]) {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }
        visited[row][col] = true;

        bool flag = existUtil(board, row + 1, col, word, index + 1) ||
                    existUtil(board, row - 1, col, word, index + 1) ||
                    existUtil(board, row, col + 1, word, index + 1) ||
                    existUtil(board, row, col - 1, word, index + 1);

        visited[row][col] = false;

        return flag;
    }
};

class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (existUtil(board, row, col, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool existUtil(vector<vector<char>> &board, int row, int col, string &word, int index) {
        if (index >= word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }
        board[row][col] = '*';

        bool flag = existUtil(board, row + 1, col, word, index + 1) ||
                    existUtil(board, row - 1, col, word, index + 1) ||
                    existUtil(board, row, col + 1, word, index + 1) ||
                    existUtil(board, row, col - 1, word, index + 1);

        board[row][col] = word[index];

        return flag;
    }
};