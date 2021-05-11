/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/house-robber-ii/
 */

class Solution {
  public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        return max(robber(nums, 0, nums.size() - 1), robber(nums, 1, nums.size()));
    }
    int robber(vector<int> &nums, int left, int right) {
        int first = 0;
        int second = nums[left];
        for (int i = left + 2; i <= right; i++) {
            int third = max(second, nums[i - 1] + first);
            first = second;
            second = third;
        }
        return second;
    }
};