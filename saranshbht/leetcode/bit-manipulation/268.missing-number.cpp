/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/missing-number/
 */

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int xor_res = n;
    for (int i = 0; i < n; i++) {
      xor_res ^= i ^ nums[i];
    }
    return xor_res;
  }
};