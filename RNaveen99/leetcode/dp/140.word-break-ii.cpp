/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-break-ii/
 */

class Solution {
    vector<string> result;

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (s.length() == 0)
            return result;
        vector<int> dp(s.size(), -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        string temp;
        helper(s, 0, words, dp, temp);
        return result;
    }
    void helper(string &s, int index, unordered_set<string> &words, vector<int> &dp, string temp) {
        if (index == s.length()) {
            temp.pop_back();
            result.push_back(temp);
            return;
        }
        string sub;
        for (int i = index; i < s.length(); ++i) {
            sub += s[i];
            if (words.count(sub)) {
                helper(s, i + 1, words, dp, temp + sub + " ");
            }
        }
    }
};