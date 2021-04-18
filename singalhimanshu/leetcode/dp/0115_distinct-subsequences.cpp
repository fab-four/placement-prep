// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
  int numDistinct(string s, string t) {
    vector<long> dp(t.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
      int prev = 1;
      for (int j = 1; j <= t.size(); j++) {
        int temp = dp[j];
        dp[j] += (s[i - 1] == t[j - 1] ? prev : 0);
        prev = temp;
      }
    }
    return dp[t.size()];
  }
};
