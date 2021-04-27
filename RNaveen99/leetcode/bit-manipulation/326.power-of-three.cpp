/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/power-of-three/
 */

class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

// since we use 32 bits to represent the number, half of the range is used for negative numbers and 0 is part
// of the positive numbers. therefore, MaxInt = 2^(32-1) -  1.
// Knowing the limitation of n, we can now deduce that the maximum value of n that is also a power of
// three is 1162261467 = 3^19.

// Therefore, the possible values of n where we should return "true" are 3^0, 3^1, ... 3 ^ { 19 }.
// Since 3 is a prime number, the only divisors of 3 ^ { 19 }  are 3^0, 3^1 ... 3 ^ { 19 },
// therefore all we need to do is divide 3 ^ { 19 } by n. A remainder of 0 means n is a divisor of 3 ^ {
// 19 } and therefore a power of three.

class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        return 1162261467 % n == 0;
    }
};