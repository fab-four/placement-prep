// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    sort(begin(words), end(words), [](const string &s1, const string &s2) {
      return s1.size() < s2.size();
    });
    vector<int> dp(words.size(), 1);
    int mx = 1;
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (isValid(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      mx = max(mx, dp[i]);
    }
    return mx;
  }

  bool isValid(const string &s1, const string &s2) {
    if (s1.size() + 1 != s2.size()) {
      return false;
    }
    int k = 0;
    for (int i = 0; i < s2.size() && k < s1.size(); i++) {
      if (s1[k] == s2[i]) {
        k++;
      }
    }
    return k == s1.size();
  }
};
