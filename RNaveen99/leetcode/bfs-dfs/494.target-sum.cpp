/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/target-sum/
 */

class Solution {
    int ways = 0;

  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        findTargetUtil(nums, target, 0);
        return ways;
    }
    void findTargetUtil(vector<int> &nums, int target, int index) {
        if (index == nums.size()) {
            if (target == 0) {
                ways++;
            }
            return;
        }

        findTargetUtil(nums, target + nums[index], index + 1);
        findTargetUtil(nums, target - nums[index], index + 1);
    }
};