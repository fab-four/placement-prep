/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sort-colors/
 */

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int size = nums.size();
        int redIndex = 0;
        int blueIndex = size - 1;

        for (int i = 0; i < size; i++) {
            if (nums[i] < 1) {
                swap(nums[i], nums[redIndex]);
                redIndex++;
            } else if (nums[i] > 1) {
                swap(nums[i], nums[blueIndex]);
                blueIndex--;
                size--;
                i--;
            }
        }
    }
};