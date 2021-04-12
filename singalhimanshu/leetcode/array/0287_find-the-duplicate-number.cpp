// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0];
    int fast = nums[0];
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (fast != slow) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return fast;
  }
};
