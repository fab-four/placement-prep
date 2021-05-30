/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/missing-number/
 */

class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i] ^ i;
        }
        return ans;
    }
};