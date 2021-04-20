// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
  // Time Complexity : O(nums.size() * target)
  // Space Complexity : O(target)
  int combinationSum4(vector<int> &nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
      for (auto num : nums) {
        if (num <= i) {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};
