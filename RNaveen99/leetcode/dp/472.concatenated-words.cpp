/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/concatenated-words/
 */

// similar to word break (139 & 140)
class TrieNode {
  public:
    bool isWord;
    vector<TrieNode *> children;

    TrieNode() {
        isWord = false;
        children = vector<TrieNode *>(26, nullptr);
    }
};
class Solution {
    TrieNode *root;

  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        root = new TrieNode();
        buildTrie(words);
        vector<string> result;
        for (string &word : words) {
            vector<int> dp(word.size() + 1, -1);
            if (isConcatenatedWord(word, 0, 1, dp)) {
                result.emplace_back(word);
            }
        }
        return result;
    }
    void buildTrie(vector<string> &words) {
        for (string &word : words) {
            TrieNode *tempRoot = root;
            for (char &c : word) {
                if (tempRoot->children[c - 'a'] == nullptr) {
                    tempRoot->children[c - 'a'] = new TrieNode();
                }
                tempRoot = tempRoot->children[c - 'a'];
            }
            tempRoot->isWord = true;
        }
    }
    bool isConcatenatedWord(string &word, int startIndex, int wordCount, vector<int> &dp) {
        if (startIndex == word.size()) {
            return wordCount > 2;
        }
        if (dp[startIndex] != -1)
            return dp[startIndex];

        TrieNode *tempRoot = root;
        for (int i = startIndex; i < word.size(); i++) {
            if (tempRoot->children[word[i] - 'a'] == nullptr) {
                return dp[startIndex] = false;
            }
            tempRoot = tempRoot->children[word[i] - 'a'];

            if (tempRoot->isWord && isConcatenatedWord(word, i + 1, wordCount + 1, dp)) {
                return dp[startIndex] = true;
            }
        }
        return dp[startIndex] = false;
    }
};