/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-average-subarray-i/
 */

class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        double avg = INT_MIN;
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i + 1 >= k) {
                avg = max(avg, (sum / k));
                sum -= nums[i + 1 - k];
            }
        }
        return avg;
    }
};