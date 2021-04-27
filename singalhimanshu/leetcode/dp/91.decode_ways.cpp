// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/decode-ways/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  int numDecodings(string s) {
    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '0') {
        continue;
      }
      dp[i] = dp[i + 1];
      if ((i < s.size() - 1) &&
          ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7'))) {
        dp[i] += dp[i + 2];
      }
    }
    return dp[0];
  }

  int rec(int pos, string s) {
    if (pos == s.size()) {
      return 1;
    }
    if (s[pos] == '0') {
      return 0;
    }
    int res = rec(pos + 1, s);
    if ((pos < s.size() - 1) &&
        ((s[pos] == '1') || (s[pos] == '2' && s[pos + 1] < '7'))) {
      res += rec(pos + 2, s);
    }
    return res;
  }
};
