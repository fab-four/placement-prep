/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-pivot-index/
 */

class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0, leftsum = 0;
        for (int x : nums)
            sum += x;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum - nums[i];
            if (leftsum == sum)
                return i;
            leftsum += nums[i];
        }
        return -1;
    }
};