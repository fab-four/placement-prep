// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int longestOnes(vector<int> &nums, int k) {
    int i = 0, j;
    int avail_flips = k;
    for (j = 0; j < nums.size(); ++j) {
      avail_flips -= (nums[j] == 0);
      if (avail_flips < 0 && nums[i++] == 0) {
        avail_flips++;
      }
    }
    return j - i;
  }
};
