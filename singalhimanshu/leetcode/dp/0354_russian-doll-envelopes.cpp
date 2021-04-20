// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    // return solve(envelopes);
    return solveOpt(envelopes);
  }

  // Time Complexity : O(n^2)
  // Space Complexity : O(n)
  int solve(vector<vector<int>> &envelopes) {
    sort(begin(envelopes), end(envelopes));
    vector<int> dp(envelopes.size(), 1);
    int mx = 1;
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (isSafe(envelopes[j][0], envelopes[j][1], envelopes[i][0],
                   envelopes[i][1])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      mx = max(mx, dp[i]);
    }
    return mx;
  }

  // Time Complexity : O(n log(n))
  // Space Complexity : O(n)
  int solveOpt(vector<vector<int>> &envelopes) {
    sort(begin(envelopes), end(envelopes),
         [](const vector<int> &p1, const vector<int> &p2) {
           return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
         });
    vector<int> dp;
    for (auto &envelop : envelopes) {
      auto it = lower_bound(begin(dp), end(dp), envelop[1]);
      if (it == end(dp)) {
        dp.emplace_back(envelop[1]);
      } else if (*it > envelop[1]) {
        *it = envelop[1];
      }
    }
    return dp.size();
  }

  inline bool isSafe(int x1, int y1, int x2, int y2) {
    return (x1 < x2) && (y1 < y2);
  }
};
