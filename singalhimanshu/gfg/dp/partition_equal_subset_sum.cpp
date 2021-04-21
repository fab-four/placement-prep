// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem/1

class Solution {
public:
  // Time Complexity : O(n * sum(arr))
  // Space Complexity : O(n * sum(arr))
  int equalPartition(int n, int arr[]) {
    int sum = accumulate(arr, arr + n, 0);
    if (sum & 1) {
      return 0;
    }
    if (subsetSum(n, arr, sum / 2)) {
      return 1;
    }
    return 0;
  }

  bool subsetSum(int n, int arr[], int target) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i < dp.size(); i++) {
      dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        if (arr[i - 1] <= j) {
          dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][target];
  }
};
