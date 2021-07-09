/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/implement-magic-dictionary/
 */

// design
class MagicDictionary {
    unordered_map<int, unordered_set<string>> hash;

  public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (string &s : dictionary) {
            hash[s.size()].emplace(s);
        }
    }

    bool search(string searchWord) {
        for (string s : hash[searchWord.size()]) {
            int count = 0;
            for (int i = 0; i < searchWord.size(); i++) {
                if (searchWord[i] != s[i]) {
                    count++;
                }
            }
            if (count == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

class TrieNode {
  public:
    vector<TrieNode *> next;
    bool isWord;
    TrieNode() {
        isWord = false;
        next = vector<TrieNode *>(26, nullptr);
    }
};
class Trie {
  private:
    TrieNode *root;

  public:
    Trie() { root = new TrieNode(); }
    void insert(string s) {
        TrieNode *cur = root;
        for (char c : s) {
            if (cur->next[c - 'a'] == NULL)
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->isWord = true;
    }

    bool find(string s, int cur_idx, int change = 0, TrieNode *cur = NULL) {
        if (!cur)
            cur = root;
        if (cur_idx == s.size())
            return cur->isWord && change == 1;
        TrieNode *next = cur->next[s[cur_idx] - 'a'];
        if (change == 1) {
            if (!next)
                return false;
            else
                return find(s, cur_idx + 1, 1, next);
        } else {
            if (next && find(s, cur_idx + 1, 0, next))
                return true;
            for (int i = 0; i < 26; i++) {
                if (s[cur_idx] == 'a' + i)
                    continue;
                if (cur->next[i] && find(s, cur_idx + 1, 1, cur->next[i]))
                    return true;
            }
            return false;
        }
    }
};
class MagicDictionary {
    Trie *trie;

  public:
    /** Initialize your data structure here. */
    MagicDictionary() { trie = new Trie(); }

    void buildDict(vector<string> dictionary) {
        for (string &s : dictionary) {
            trie->insert(s);
        }
    }

    bool search(string searchWord) { return trie->find(searchWord, 0); }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

class MagicDictionary {
    unordered_map<string, char> map;

  public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (string &word : dictionary) {
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                temp[i] = '0';
                if (!map.count(temp))
                    map[temp] = word[i];
                else if (map[temp] != word[i])
                    map[temp] = '0';
            }
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < searchWord.size(); i++) {
            string temp = searchWord;
            temp[i] = '0';
            if (map.count(temp) && map[temp] != searchWord[i])
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */