// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    auto nums_size = nums.size();
    int cur_sum = nums[0];
    int max_sum = cur_sum;
    for (size_t i = 1; i < nums_size; i++) {
      cur_sum = max(cur_sum + nums[i], nums[i]);
      max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
  }
};
