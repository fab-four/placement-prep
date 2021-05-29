/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sort-array-by-parity-ii/
 */

class Solution {
  public:
    vector<int> sortArrayByParityII(vector<int> &nums) {
        int size = nums.size();
        int oddIndex = 1;
        for (int i = 0; i < size; i += 2) {
            if (nums[i] & 1) {
                while (nums[oddIndex] & 1) {
                    oddIndex += 2;
                }
                swap(nums[i], nums[oddIndex]);
            }
        }
        return nums;
    }
};