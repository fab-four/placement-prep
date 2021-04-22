// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/target-sum/

class Solution {
public:
  // Time Complexity : O(n * sum(nums))
  // Space Complexity : O(n * sum(nums))
  int findTargetSumWays(vector<int> &nums, int target) {
    return countSubsetSumDiff(nums, target);
  }

  int countSubsetSumDiff(const vector<int> &nums, int target) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if (((sum + target) & 1) || (target > sum)) {
      return 0;
    }
    int find_sum = (target + sum) / 2;
    return countSubsetSum(nums, find_sum);
  }

  int countSubsetSum(const vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = target; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[target];
  }
};
