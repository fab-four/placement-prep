// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution {
public:
  // Time Complexity : O(n^2)
  // Space Complexity : O(n)
  int LongestBitonicSequence(vector<int> nums) {
    vector<int> lis(nums.size(), 1);
    for (int i = 1; i < lis.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          lis[i] = max(lis[i], 1 + lis[j]);
        }
      }
    }
    vector<int> lds(nums.size(), 1);
    for (int i = lds.size() - 2; i >= 0; i--) {
      for (int j = lds.size() - 1; j > i; j--) {
        if (nums[j] < nums[i]) {
          lds[i] = max(lds[i], 1 + lds[j]);
        }
      }
    }
    int mx = lis[0] + lds[0] - 1;
    for (int i = 1; i < lis.size(); i++) {
      mx = max(mx, lis[i] + lds[i] - 1);
    }
    return mx;
  }
};
