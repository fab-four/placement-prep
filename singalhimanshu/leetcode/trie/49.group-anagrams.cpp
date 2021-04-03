/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

class TrieNode {
public:
  int idx;
  unordered_map<char, TrieNode *> children;
  char data;
  TrieNode(char d) : data(d), idx(-1) {}
};

class Trie {
public:
  TrieNode *root;
  Trie() : root(new TrieNode('\0')) {}
  ~Trie() { delete root; }
};

int findWordIdx(Trie *trie, const string &word, int &anagram_idx) {
  TrieNode *temp = trie->root;
  for (const auto &c : word) {
    if (temp->children.count(c) == 0) {
      temp->children[c] = new TrieNode(c);
    }
    temp = temp->children[c];
  }
  if (temp->idx == -1) {
    temp->idx = ++anagram_idx;
  }
  return temp->idx;
}

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    Trie *trie = new Trie();
    int anagram_idx = -1;
    vector<vector<string>> result;
    for (const auto &str : strs) {
      string temp_str = str;
      sort(begin(temp_str), end(temp_str));
      int word_idx = findWordIdx(trie, temp_str, anagram_idx);
      if (result.size() == word_idx) {
        result.emplace_back(move(vector<string>{str}));
      } else {
        result[word_idx].emplace_back(str);
      }
    }
    delete trie;
    return result;
  }
};
// @lc code=end
