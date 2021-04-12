// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int dup_count = 0;
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i - 1] == nums[i]) {
        dup_count++;
        continue;
      }
      nums[i - dup_count] = nums[i];
    }
    return nums.size() - dup_count;
  }
};
