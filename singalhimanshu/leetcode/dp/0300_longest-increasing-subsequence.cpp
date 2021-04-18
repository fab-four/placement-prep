// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    return lisOpt(nums);
    // return lis(nums);
  }

  // Time Complexity : O(n^2)
  // Space Complexity : O(n)
  int lis(const vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    int ans = 0;
    for (const auto &ele : dp) {
      ans = max(ans, ele);
    }
    return ans;
  }

  // Time Complexity : O(log(n))
  // Space Complexity : O(n)
  int lisOpt(const vector<int> &nums) {
    vector<int> tail;
    tail.reserve(tail.size());
    tail.emplace_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > tail.back()) {
        tail.emplace_back(nums[i]);
      } else {
        int ceil_idx = getCeilIdx(tail, nums[i]);
        tail[ceil_idx] = nums[i];
      }
    }
    return tail.size();
  }

  int getCeilIdx(const vector<int> &tail, int target) {
    int l = 0, r = tail.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (tail[mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
