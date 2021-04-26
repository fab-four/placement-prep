// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int minSubArrayLen(int target, vector<int> &nums) {
    int sum = 0;
    int i = 0, j = 0;
    int ans = INT_MAX;
    while (j < nums.size()) {
      sum += nums[j];
      while (sum >= target) {
        ans = min(ans, j - i + 1);
        sum -= nums[i];
        i++;
      }
      j++;
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
