// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/word-search/

constexpr array<int, 4> dx = {1, -1, 0, 0};
constexpr array<int, 4> dy = {0, 0, 1, -1};

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.size() == 0 || board[0].size() == 0) {
      return false;
    }
    vector<vector<bool>> vis(board.size(),
                             vector<bool>(board[0].size(), false));
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (dfs(r, c, 0, board, word, vis)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(int cr, int cc, int word_idx, const vector<vector<char>> &board,
           const string &word, vector<vector<bool>> &vis) {
    if (isOutOfBounds(cr, cc, board.size(), board[0].size()) || vis[cr][cc] ||
        (board[cr][cc] != word[word_idx])) {
      return false;
    }
    vis[cr][cc] = true;
    word_idx++;
    if (word_idx == word.size()) {
      return true;
    }

    for (int i = 0; i < dx.size(); i++) {
      if (dfs(cr + dx[i], cc + dy[i], word_idx, board, word, vis)) {
        return true;
      }
    }
    vis[cr][cc] = false;
    return false;
  }

  bool isOutOfBounds(int r, int c, int rows, int cols) {
    return (r < 0) || (c < 0) || (r >= rows) || (c >= cols);
  }

private:
};
