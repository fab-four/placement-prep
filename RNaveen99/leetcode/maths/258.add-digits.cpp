/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/add-digits/
 */

class Solution {
  public:
    int addDigits(int num) {
        while (num > 9) {
            num = digitSum(num);
        }
        return num;
    }
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
};

// compute digital root
class Solution {
  public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};