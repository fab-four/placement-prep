// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
  // Time Complexity : O(n^2)
  // Space Complexity : O(1)
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3) {
      return INT_MAX;
    }
    int res = nums[0] + nums[1] + nums[2];
    sort(begin(nums), end(nums));
    for (int fixed_ptr = 0; fixed_ptr < nums.size() - 2; fixed_ptr++) {
      if (fixed_ptr > 0 && nums[fixed_ptr] == nums[fixed_ptr - 1]) {
        continue;
      }
      int left_ptr = fixed_ptr + 1;
      int right_ptr = nums.size() - 1;
      while (left_ptr < right_ptr) {
        int cur_sum = nums[fixed_ptr] + nums[left_ptr] + nums[right_ptr];
        if (cur_sum == target) {
          return cur_sum;
        }
        if (abs(target - cur_sum) < abs(target - res)) {
          res = cur_sum;
        }
        if (cur_sum > target) {
          right_ptr--;
        } else {
          left_ptr++;
        }
      }
    }
    return res;
  }
};
