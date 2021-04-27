// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) {
      return 0;
    }
    int left_ptr = 0, cur_prod = 1;
    int res = 0;
    for (int right_ptr = 0; right_ptr < nums.size(); right_ptr++) {
      cur_prod *= nums[right_ptr];
      while (cur_prod >= k) {
        cur_prod /= nums[left_ptr];
        left_ptr++;
      }
      res += right_ptr - left_ptr + 1;
    }
    return res;
  }
};
