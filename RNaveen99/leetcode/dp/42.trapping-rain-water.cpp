/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/trapping-rain-water/
 */

class Solution {
  public:
    int trap(vector<int> &height) {
        int size = height.size();
        if (size == 0)
            return 0;

        vector<int> left_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        vector<int> right_max(size);
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int ans = 0;
        // note: first and last block will not collect any water
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

class Solution {
  public:
    int trap(vector<int> &height) {
        int size = height.size();
        if (size == 0)
            return 0;

        int ans = 0;
        int left = 0;
        int right = size - 1;
        int left_max = 0;
        int right_max = 0;

        while (left <= right) {
            if (left_max < height[left]) {
                left_max = height[left];
            }
            if (right_max < height[right]) {
                right_max = height[right];
            }

            if (left_max < right_max) {
                ans += left_max - height[left];
                left++;
            } else {
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};