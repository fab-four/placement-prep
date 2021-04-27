// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  vector<int> sortedSquares(vector<int> &nums) {
    int left_ptr = 0, right_ptr = nums.size() - 1;
    vector<int> res(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (abs(nums[right_ptr]) > abs(nums[left_ptr])) {
        res[i] = nums[right_ptr] * nums[right_ptr];
        right_ptr--;
      } else {
        res[i] = nums[left_ptr] * nums[left_ptr];
        left_ptr++;
      }
    }
    return res;
  }
};
