// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/jump-game/

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int dis = 0;
    for (int i = 0; i <= dis; i++) {
      dis = max(dis, nums[i] + i);
      if (dis > nums.size() - 1) {
        return true;
      }
    }
    return false;
  }
};
