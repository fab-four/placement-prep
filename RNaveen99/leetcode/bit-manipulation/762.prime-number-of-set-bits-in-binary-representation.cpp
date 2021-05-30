/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 */

class Solution {
  public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i = L; i <= R; ++i) {
            if (isSmallPrime(std::bitset<20>(i).count())) {
                count++;
            }
        }
        return count;
    }
    bool isSmallPrime(int n) {
        switch (n) {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
            return true;
        default:
            return false;
        }
    }
};