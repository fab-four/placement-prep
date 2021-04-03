/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start

class TrieNode {
public:
  TrieNode *left;
  TrieNode *right;
};

class Trie {
public:
  TrieNode *root;
  Trie() : root(new TrieNode()) {}
  ~Trie() { delete root; }
  void insert(int num);
};

void Trie::insert(int num) {
  TrieNode *temp = root;
  for (int i = 31; i >= 0; i--) {
    int current_bit = (num >> i) & 1;
    if (current_bit) {
      if (temp->right == nullptr) {
        temp->right = new TrieNode();
      }
      temp = temp->right;
    } else {
      if (temp->left == nullptr) {
        temp->left = new TrieNode();
      }
      temp = temp->left;
    }
  }
}

class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int max_xor = 0;
    Trie *trie = new Trie();
    for (const auto &num : nums) {
      trie->insert(num);
      int cur_max_xor = findMaximumXORHelper(trie, num);
      max_xor = max(max_xor, cur_max_xor);
    }
    delete trie;
    return max_xor;
  }

  int findMaximumXORHelper(Trie *trie, int num) {
    int max_xor = 0;
    TrieNode *temp = trie->root;
    for (int i = 31; i >= 0; i--) {
      int current_bit = (num >> i) & 1;
      if (current_bit) {
        if (temp->left) {
          temp = temp->left;
          max_xor += 1 << i;
        } else {
          temp = temp->right;
        }
      } else {
        if (temp->right) {
          temp = temp->right;
          max_xor += 1 << i;
        } else {
          temp = temp->left;
        }
      }
    }
    return max_xor;
  }
};
// @lc code=end
