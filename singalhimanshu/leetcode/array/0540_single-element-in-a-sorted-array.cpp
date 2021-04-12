// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (low + high) / 2;
      if (nums[mid] == nums[mid ^ 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};
