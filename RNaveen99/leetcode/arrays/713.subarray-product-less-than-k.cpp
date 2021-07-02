/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/subarray-product-less-than-k/
 */

// sliding window
class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1)
            return 0;
        int product = 1;
        int count = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            product = product * nums[right];
            while (product >= k) {
                product = product / nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};