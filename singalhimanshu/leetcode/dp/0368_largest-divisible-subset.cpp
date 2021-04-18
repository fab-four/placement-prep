// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
  // Time Complexity: O(n^2)
  // Space Complexity: O(n)
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<int> dp(nums.size(), 1);
    vector<int> parent(nums.size(), -1);
    int mx = 0;
    int idx = -1;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] != 0) {
          continue;
        }
        if (1 + dp[j] > dp[i]) {
          dp[i] = 1 + dp[j];
          parent[i] = j;
        }
      }
      if (dp[i] > mx) {
        idx = i;
        mx = dp[i];
      }
    }
    vector<int> res;
    while (idx != -1) {
      res.emplace_back(nums[idx]);
      idx = parent[idx];
    }
    return res;
  }
};
