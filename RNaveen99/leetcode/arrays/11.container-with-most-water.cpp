/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/container-with-most-water/
 */

// Array, Two pointers
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            maxWater = max(maxWater, width * minHeight);
            if (minHeight == height[left])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            maxWater = max(maxWater, width * minHeight);
            while (height[left] <= minHeight && left < right)
                left++;
            while (height[right] <= minHeight && left < right)
                right--;
        }
        return maxWater;
    }
};