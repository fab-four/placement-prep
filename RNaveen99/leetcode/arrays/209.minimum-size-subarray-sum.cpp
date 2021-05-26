/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-size-subarray-sum/
 */

// sliding window
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0;
        int right = 0;
        int minSize = INT_MAX;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            right++;

            while (sum >= target && left <= right) {
                minSize = min(minSize, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};