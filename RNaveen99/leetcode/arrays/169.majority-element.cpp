/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/majority-element/
 */

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int majorityIndex = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[majorityIndex]) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    majorityIndex = i;
                    count = 1;
                }
            }
        }
        return nums[majorityIndex];
    }
};