// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    return quickselect(nums, 0, nums.size() - 1, k - 1);
  }

  int quickselect(vector<int> &nums, int lo, int hi, int k) {
    int rand_pivot_idx = lo + rand() % (hi - lo + 1);
    int pivot_idx = getPivotIdx(nums, rand_pivot_idx, lo, hi);
    if (pivot_idx == k) {
      return nums[pivot_idx];
    }
    if (pivot_idx < k) {
      return quickselect(nums, pivot_idx + 1, hi, k);
    }
    return quickselect(nums, lo, pivot_idx - 1, k);
  }

  int getPivotIdx(vector<int> &nums, int rand_pivot_idx, int lo, int hi) {
    swap(nums[hi], nums[rand_pivot_idx]);
    int pivot = nums[hi];
    int i = lo, j = lo;
    while (i <= hi) {
      if (nums[i] >= pivot) {
        swap(nums[i], nums[j]);
        i++;
        j++;
        continue;
      }
      i++;
    }
    return j - 1;
  }
};
