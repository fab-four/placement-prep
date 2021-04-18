// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    return solveOpt(nums);
    // return solveLIS(nums);
  }

  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int solveOpt(const vector<int> &nums) {
    array<int, 10001> dp = {0};
    for (const auto &num : nums) {
      dp[num] += num;
    }
    int mx = 0;
    for (int i = 2; i < dp.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
      mx = max(mx, dp[i]);
    }
    return mx;
  }

  // Time Complexity: O(n^2)
  // Space Complexity: O(n)
  int solveLIS(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<int> dp(begin(nums), end(nums));
    int mx = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] + 1 != nums[i]) {
          dp[i] = max(dp[i], nums[i] + dp[j]);
        }
      }
      mx = max(mx, dp[i]);
    }
    return mx;
  }
};
