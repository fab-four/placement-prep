/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 */

// store every number on 1 ahead of its index so that the value of its index will give elements smaller than
// it and also covers case for nums[i] == 0

class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> frequency(102, 0);

        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i] + 1]++;
        }
        for (int i = 1; i < 102; i++) {
            frequency[i] += frequency[i - 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = frequency[nums[i]];
        }
        return nums;
    }
};