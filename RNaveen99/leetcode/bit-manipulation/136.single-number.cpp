/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/single-number/
 */

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int num = 0;
        for (int ele : nums) {
            num = num ^ ele;
        }
        return num;
    }
};