/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/power-of-two/
 */

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        int num = n & (n - 1);
        return num ? false : true;
    }
};