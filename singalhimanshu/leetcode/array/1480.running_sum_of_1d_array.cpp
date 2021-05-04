// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  vector<int> runningSum(vector<int> &nums) {
    vector<int> prefix_sum(nums.size());
    prefix_sum[0] = nums[0];
    for (int i = 1; i < prefix_sum.size(); i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }
    return prefix_sum;
  }
};
