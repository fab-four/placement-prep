/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
  public:
    int jump(vector<int> &nums) {
        int maxReachableIndex = 0;
        int currentEnd = 0;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1 && i <= maxReachableIndex; i++) {
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
            if (i == currentEnd) {
                steps++;
                currentEnd = maxReachableIndex;
            }
        }
        return steps;
    }
};