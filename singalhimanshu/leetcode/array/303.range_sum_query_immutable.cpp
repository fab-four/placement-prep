// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  NumArray(vector<int> &nums) {
    prefix_sum.resize(nums.size());
    prefix_sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }
  }

  // Time Complexity : O(1)
  // Space Complexity : O(n)
  int sumRange(int left, int right) {
    if (left == 0) {
      return prefix_sum[right];
    }
    return prefix_sum[right] - prefix_sum[left - 1];
  }

private:
  vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
