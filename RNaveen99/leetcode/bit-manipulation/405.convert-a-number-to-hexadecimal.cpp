/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 */

class Solution {
    string HEX = "0123456789abcdef";

  public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string result;

        // because negative numbers are stored in 2's complement
        // Hexadecimal uses 4 bits .... so 32/4 = 8
        while (num && result.size() < 8) {
            result += HEX[num & 15];
            num >>= 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};