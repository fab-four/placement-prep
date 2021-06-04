/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/implement-trie-prefix-tree/
 */

class TrieNode {
  public:
    unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode() { isWord = false; }
    ~TrieNode() {
        for (auto child : children) {
            delete child.second;
        }
    }
};
class Trie {
    TrieNode *root;

  public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *itr = root;
        for (char c : word) {
            if (itr->children.find(c) == itr->children.end()) {
                itr->children[c] = new TrieNode();
            }
            itr = itr->children[c];
        }
        itr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *itr = root;
        for (char c : word) {
            if (itr->children.find(c) == itr->children.end()) {
                return false;
            }
            itr = itr->children[c];
        }
        return itr->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *itr = root;
        for (char c : prefix) {
            if (itr->children.find(c) == itr->children.end()) {
                return false;
            }
            itr = itr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class TrieNode {
  public:
    vector<TrieNode *> children;
    bool isWord;

    TrieNode() {
        isWord = false;
        children = vector<TrieNode *>(26, nullptr);
    }
    ~TrieNode() {
        for (auto child : children) {
            delete child;
        }
    }
};
class Trie {
    TrieNode *root;

  public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *itr = root;
        for (char c : word) {
            int index = c - 'a';
            if (itr->children[index] == nullptr) {
                itr->children[index] = new TrieNode();
            }
            itr = itr->children[index];
        }
        itr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *itr = root;
        for (char c : word) {
            int index = c - 'a';
            if (itr->children[index] == nullptr) {
                return false;
            }
            itr = itr->children[index];
        }
        return itr->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *itr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (itr->children[index] == nullptr) {
                return false;
            }
            itr = itr->children[index];
        }
        return true;
    }
};
