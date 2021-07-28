/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-break/
 */

class Solution {
  public:
    int helper(string &s, int index, unordered_set<string> &words, vector<int> &dp) {
        if (index == s.length())
            return true;
        if (dp[index] != -1)
            return dp[index];
        string sub;
        for (int i = index; i < s.length(); ++i) {
            sub += s[i];
            if (words.count(sub) && helper(s, i + 1, words, dp)) {
                dp[index] = 1;
                return 1;
            }
        }
        dp[index] = 0;
        return 0;
    }
    bool wordBreak(string s, vector<string> &wordDict) {
        if (s.length() == 0)
            return true;
        vector<int> dp(s.size(), -1);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return helper(s, 0, words, dp);
    }
};
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.length();
        if (n == 0)
            return true;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(n + 1, 0);
        // emptry string is true
        dp[0] = 1;
        // start with 1 so that we can use substr(j, i-j)
        // l e e t c o d e
        // 0 1 2 3 4 5 6 7
        // i.e. j=0 and i= 8 then s.substr(j, i-j) = s.substr(0, 8) -> correctly gives full string
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    // break;
                }
            }
        }
        return dp[n];
    }
};