/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-1-bits/
 */

// Bit-wise AND of two numbers n and n - 1 always flips the least significant 1 - bit in n to 0, and
// keeps all other bits the same.
class Solution {
  public:
    int hammingWeight(uint32_t n) {
        unsigned int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};