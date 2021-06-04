/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-search-ii/
 */

class TrieNode {
  public:
    string wordFormed;
    vector<TrieNode *> children;

    TrieNode() {
        wordFormed = "";
        children = vector<TrieNode *>(26, nullptr);
    }
};
class Solution {
    vector<string> result;
    TrieNode *root;

  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        buildTrieFromWords(words);

        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, words, root, r, c, rows, cols);
            }
        }
        return result;
    }
    void buildTrieFromWords(vector<string> words) {
        root = new TrieNode();
        for (string word : words) {
            TrieNode *itr = root;
            for (char c : word) {
                int index = c - 'a';
                if (itr->children[index] == nullptr) {
                    itr->children[index] = new TrieNode();
                }
                itr = itr->children[index];
            }
            itr->wordFormed = word;
        }
    }

    void dfs(vector<vector<char>> &board, vector<string> &words, TrieNode *itr, int r, int c, int &rows,
             int &cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;

        int index = board[r][c] - 'a';
        if (board[r][c] == '#' || itr->children[index] == nullptr)
            return;

        itr = itr->children[index];
        if (itr->wordFormed != "") {
            result.emplace_back(itr->wordFormed);
            itr->wordFormed = "";
        }
        board[r][c] = '#';
        dfs(board, words, itr, r + 1, c, rows, cols);
        dfs(board, words, itr, r - 1, c, rows, cols);
        dfs(board, words, itr, r, c + 1, rows, cols);
        dfs(board, words, itr, r, c - 1, rows, cols);
        board[r][c] = index + 'a';
    }
};