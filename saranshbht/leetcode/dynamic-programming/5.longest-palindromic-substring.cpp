/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://leetcode.com/problems/longest-palindromic-substring/
 */

class Solution {
public:
  string longestPalindrome(string s) {
    // TC : O(n^2). SC: O(n^2). DP
    int n = s.size();
    if (n == 1)
      return s;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, end = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);

        if (dp[i][j] && (j - i > end - start)) {
          start = i;
          end = j;
        }
      }
    }
    return s.substr(start, end - start + 1);

    // TC : O(n^2). SC: O(1). without DP
    // see Manacher's algorithm for O(n)
    int n = s.size();
    if (n == 1)
      return s;

    int start = 0;
    int end = 0;
    for (int i = 0; i < n - 1; i++) {
      int len1 = getLongestPalindromeLen(s, i, i);
      int len2 = getLongestPalindromeLen(s, i, i + 1);
      int len = max(len1, len2);
      if (len > end - start + 1) {
        start = i - len / 2 + (len == len2);
        end = i + len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }

  int getLongestPalindromeLen(string &s, int l, int r) {
    int n = s.size();
    while (l >= 0 && r < n && s[l] == s[r]) {
      l--;
      r++;
    }
    return r - l - 1;
  }
};