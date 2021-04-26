// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/missing-number/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int missingNumber(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans ^= i;
      ans ^= nums[i];
    }
    ans ^= nums.size();
    return ans;
  }
};
