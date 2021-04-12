/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-subarray/
 */

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int globalMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int currentSum = 0;
            for (int j = i; j < nums.size(); j++) {
                currentSum += nums[j];
                globalMax = max(currentSum, globalMax);
            }
        }
        return globalMax;
    }
};

// Kadane's Algorithm
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int globalMax = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (currentMax >= 0) {
                currentMax += nums[i];
            } else {
                currentMax = nums[i];
            }
            if (currentMax > globalMax) {
                globalMax = currentMax;
            }
        }
        return globalMax;
    }
};