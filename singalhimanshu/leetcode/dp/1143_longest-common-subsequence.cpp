// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    return solveTab(text1, text2);
    // vector<vector<int>> memo(text1.size() + 1,
    //                          vector<int>(text2.size() + 1, -1));
    // return solveMemo(text1.size(), text2.size(), text1, text2, memo);
  }

  int solveTab(const string &text1, const string &text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); i++) {
      for (int j = 1; j <= text2.size(); j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[text1.size()][text2.size()];
  }

  int solveMemo(int cr, int cc, const string &text1, const string &text2,
                vector<vector<int>> &memo) {
    if (cr == 0 || cc == 0) {
      return memo[cr][cc] = 0;
    }
    if (memo[cr][cc] != -1) {
      return memo[cr][cc];
    }
    if (text1[cr - 1] == text2[cc - 1]) {
      memo[cr][cc] = 1 + solveMemo(cr - 1, cc - 1, text1, text2, memo);

    } else {
      memo[cr][cc] = max(solveMemo(cr - 1, cc, text1, text2, memo),
                         solveMemo(cr, cc - 1, text1, text2, memo));
    }
    return memo[cr][cc];
  }
};
