/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/global-and-local-inversions/
 */

class Solution {
  public:
    bool isIdealPermutation(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i] - i) >= 2)
                return false;
        }
        return true;
    }
};