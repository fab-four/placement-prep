// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/edit-distance/

class Solution {
public:
  int minDistance(string word1, string word2) {
    return solveTab(word1, word2);
    // return solveMemo(word1, word2);
  }

  int solveTab(const string &word1, const string &word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    for (int i = 0; i < word2.size() + 1; i++) {
      dp[0][i] = i;
    }
    for (int i = 0; i < word1.size() + 1; i++) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }

  int solveMemo(const string &word1, const string &word2) {
    vector<vector<int>> memo(word1.size() + 1,
                             vector<int>(word2.size() + 1, -1));
    return solveMemoRec(word1.size(), word2.size(), word1, word2, memo);
  }

  int solveMemoRec(int i1, int i2, const string &word1, const string &word2,
                   vector<vector<int>> &memo) {
    if (i1 == 0) {
      return i2;
    }
    if (i2 == 0) {
      return i1;
    }
    if (memo[i1][i2] != -1) {
      return memo[i1][i2];
    }
    if (word1[i1 - 1] == word2[i2 - 1]) {
      return memo[i1][i2] = solveMemoRec(i1 - 1, i2 - 1, word1, word2, memo);
    }
    // {i1 - 1, i2 - 1} -> replace
    // {i1 - 1, i2} -> delete
    // {i1, i2 - 1} -> add
    memo[i1][i2] = 1 + min(solveMemoRec(i1 - 1, i2 - 1, word1, word2, memo),
                           min(solveMemoRec(i1 - 1, i2, word1, word2, memo),
                               solveMemoRec(i1, i2 - 1, word1, word2, memo)));
    return memo[i1][i2];
  }
};
