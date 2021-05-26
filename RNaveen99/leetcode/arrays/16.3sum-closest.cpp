/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/3sum-closest/
 */

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int maxSum = 0;
        for (int i = 0; i < size; i++) {
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    maxSum = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return maxSum;
    }
};