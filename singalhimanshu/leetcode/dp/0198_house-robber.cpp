// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/house-robber/

class Solution {
public:
  int rob(vector<int> &nums) {
    // return robTab(nums);
    return robMemOpt(nums);
  }

  // Time Complexity : O(n)
  // Space Complexity : O(n)
  int robTab(const vector<int> &nums) {
    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i < nums.size() + 1; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
  }

  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int robMemOpt(const vector<int> &nums) {

    int prev1 = 0;
    int prev2 = 0;
    for (const auto &num : nums) {
      int temp = prev1;
      prev1 = max(prev1, prev2 + num);
      prev2 = temp;
    }
    return prev1;
  }
};
