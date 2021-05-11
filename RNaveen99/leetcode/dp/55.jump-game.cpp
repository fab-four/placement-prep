/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/jump-game/
 */

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int maxReachableIndex = 0;
        for (int i = 0; i < nums.size() - 1 && i <= maxReachableIndex; i++) {
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
        }
        return maxReachableIndex >= nums.size() - 1 ? true : false;
    }
};