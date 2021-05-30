/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 */

class Solution {
  public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int needed = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close > open) {
                needed++;
                close--;
            }
            if (open > 0 && close > 0) {
                open -= close;
                close = 0;
            }
        }
        return needed + open;
    }
};