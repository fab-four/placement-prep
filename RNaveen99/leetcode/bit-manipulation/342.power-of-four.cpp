/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/power-of-four/
 */

class Solution {
  public:
    bool isPowerOfFour(int num) {
        if (num < 1)
            return false;
        // hexadecimal digit with 1 on odd places and 0 on even places
        int mask = 0x55555555;
        return (num & (num - 1)) == 0 && (num | mask) == mask;
        // return (num & (num - 1)) == 0 && (num & mask) != 0;
    }
};

class Solution {
  public:
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};