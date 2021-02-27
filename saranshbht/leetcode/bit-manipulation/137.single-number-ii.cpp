/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/single-number-ii/
 */

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // magic
    // int one = 0, two = 0;
    // int n = nums.size();
    // for (int i = 0; i < n; i++) {
    //     one = (one ^ nums[i]) & ~two;
    //     two = (two ^ nums[i]) & ~one;
    // }
    // return one;

    vector<int> bitSum(32, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int k = nums[i];
      for (int j = 31; j >= 0 && k; j--, k >>= 1) {
        bitSum[j] += k & 1;
      }
    }

    int res = 0;
    for (int j = 31; j >= 0; j--) {
      if (bitSum[j] % 3) {
        res += 1 << (31 - j);
      }
    }
    return res;
  }
};