// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/implement-magic-dictionary/

/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 */

// @lc code=start

class TrieNode {
public:
  array<TrieNode *, 26> children{nullptr};
  bool is_terminal;
  TrieNode() : is_terminal(false) {}
};

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() : m_root(new TrieNode()) {}
  void insert(const string &word);
  void buildDict(const vector<string> &dictionary);
  bool found(const string &search_word);
  bool search(string search_word);

private:
  TrieNode *m_root;
};

void MagicDictionary::insert(const string &word) {
  TrieNode *temp = m_root;
  for (const auto &c : word) {
    if (temp->children[c - 'a'] == nullptr) {
      temp->children[c - 'a'] = new TrieNode();
    }
    temp = temp->children[c - 'a'];
  }
  temp->is_terminal = true;
}

void MagicDictionary::buildDict(const vector<string> &dictionary) {
  for (const auto &word : dictionary) {
    insert(word);
  }
}

bool MagicDictionary::found(const string &search_word) {
  TrieNode *temp = m_root;
  for (const char &c : search_word) {
    if (temp->children[c - 'a'] == nullptr) {
      return false;
    }
    temp = temp->children[c - 'a'];
  }
  return temp->is_terminal;
}

bool MagicDictionary::search(string search_word) {
  for (size_t i = 0; i < search_word.size(); i++) {
    char cur_char = search_word[i];
    for (char c = 'a'; c <= 'z'; c++) {
      if (c == cur_char) {
        continue;
      }
      search_word[i] = c;
      if (found(search_word)) {
        return true;
      }
    }
    search_word[i] = cur_char;
  }
  return false;
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end
