/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/monotone-increasing-digits/
 */

// Reference :
// https://leetcode.com/problems/monotone-increasing-digits/discuss/109811/Simple-and-very-short-C++-solution/485997

class Solution {
  public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);
        int marker = number.size();
        for (int i = number.size() - 2; i >= 0; i--) {
            if (number[i] > number[i + 1]) {
                marker = i;
                number[i] = number[i] - 1;
            }
        }
        for (int i = marker + 1; i < number.size(); i++) {
            number[i] = '9';
        }
        return stoi(number);
    }
};