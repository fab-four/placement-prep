// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition/1

class Solution {
public:
  // Time Complexity : O(n * sum(arr))
  // Space Complexity : O(n * sum(arr))
  int minDiffernce(int arr[], int n) {
    int sum = accumulate(arr, arr + n, 0);
    vector<int> possible_sums = subsetSum(arr, n, sum);
    int mn = INT_MAX;
    for (auto ele : possible_sums) {
      mn = min(mn, sum - (2 * ele));
    }
    return mn;
  }

  vector<int> subsetSum(int arr[], int n, int target) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i < dp.size(); i++) {
      dp[i][0] = true;
    }
    for (int i = 1; i < dp.size(); i++) {
      for (int j = 1; j <= target; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < (dp[0].size() + 1) / 2; i++) {
      if (dp[dp.size() - 1][i]) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};
