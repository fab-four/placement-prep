/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/count-numbers-with-unique-digits/
 */

// Simple Combinatorics concept
// f(n) = count of number with unique digits of "length n"
// f(1) = 10, f(2) = 9 * 9 = 81, f(3) = f(2) * 8 = 9 * 9 * 8, f(4) = f(3) * 7 = 9 * 9 * 8 * 7 and so on..
// Hence return f(1) + f(2) + .. + f(n)
// Any number with length > 10 couldn't be unique digits number
class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;

        int sum = 10;
        int digitsAvailable = 9;
        int temp = 9;
        while (n > 1) {
            temp *= digitsAvailable;
            sum += temp;
            digitsAvailable--;
            n--;
        }

        return sum;
    }
};