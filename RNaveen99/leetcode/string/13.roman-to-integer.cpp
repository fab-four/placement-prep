/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/roman-to-integer/
 */

class Solution {
  public:
    int charToInt(char ele) {
        switch (ele) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum = charToInt(s[0]);
        for (int i = 1; i < s.length(); i++) {
            int prev = charToInt(s[i - 1]);
            int curr = charToInt(s[i]);
            if (prev < curr) {
                curr -= prev;
                sum -= prev;
            }
            sum += curr;
        }
        return sum;
    }
};