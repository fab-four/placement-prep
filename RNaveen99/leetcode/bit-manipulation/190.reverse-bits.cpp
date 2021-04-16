/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-bits/
 */

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        unsigned result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            int LSB = n & 1;
            n = n >> 1;
            result = result | LSB;
        }
        return result;
    }
};