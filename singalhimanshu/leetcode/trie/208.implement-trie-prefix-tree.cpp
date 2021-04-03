// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/implement-trie-prefix-tree/

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

class TrieNode {
public:
  char data;
  unordered_map<char, TrieNode *> children;
  bool is_terminal;
  TrieNode(char d) : data(d), is_terminal(false) {}
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode('\0')) {}

  /** Inserts a word into the trie. */
  void insert(string word);

  /** Returns if the word is in the trie. */
  bool search(string word);

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix);

private:
  TrieNode *root;
};

void Trie::insert(string word) {
  TrieNode *temp = root;
  for (const auto &c : word) {
    if (temp->children.count(c)) {
      temp = temp->children[c];
    } else {
      TrieNode *new_node = new TrieNode(c);
      temp->children[c] = new_node;
      temp = new_node;
    }
  }
  temp->is_terminal = true;
}

bool Trie::search(string word) {
  TrieNode *temp = root;
  for (const auto &c : word) {
    if (temp->children.count(c) == 0) {
      return false;
    }
    temp = temp->children[c];
  }
  return temp->is_terminal;
}

bool Trie::startsWith(string prefix) {
  TrieNode *temp = root;
  for (const auto &c : prefix) {
    if (temp->children.count(c) == 0) {
      return false;
    }
    temp = temp->children[c];
  }
  return true;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
