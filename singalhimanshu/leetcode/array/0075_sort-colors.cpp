// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int lo = 0, mid = 0, hi = nums.size() - 1;
    while (mid <= hi) {
      switch (nums[mid]) {
      case 0:
        swap(nums[lo], nums[mid]);
        lo++;
        mid++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(nums[mid], nums[hi]);
        hi--;
        break;
      }
    }
  }
};
