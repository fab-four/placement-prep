/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/design-add-and-search-words-data-structure/
 */

class WordDictionary {
    unordered_map<int, unordered_set<string>> hash;

  public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    void addWord(string word) { hash[word.size()].emplace(word); }

    bool search(string word) {
        for (string s : hash[word.size()]) {
            bool flag = true;
            for (int i = 0; i < word.size() && flag; i++) {
                if (s[i] == word[i] || word[i] == '.' || s[i] == '.') {
                    continue;
                }
                flag = false;
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */