class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  int pivotIndex(vector<int> &nums) {
    vector<int> prefix_sum(nums.size(), 0);
    prefix_sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i];
    }
    for (int i = 0; i < prefix_sum.size(); i++) {
      int left_sum = prefix_sum[i] - nums[i];
      int right_sum = prefix_sum.back() - prefix_sum[i];
      if (left_sum == right_sum) {
        return i;
      }
    }
    return -1;
  }
};
