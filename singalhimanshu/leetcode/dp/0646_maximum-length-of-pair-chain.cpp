// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    sort(begin(pairs), end(pairs));
    vector<int> dp(pairs.size(), 1);
    for (int i = 1; i < pairs.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[j][1] < pairs[i][0]) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }
    int mx = 0;
    for (const auto &ele : dp) {
      mx = max(mx, ele);
    }
    return mx;
  }
};
