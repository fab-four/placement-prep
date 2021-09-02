/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 */

class Solution {
  public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                open--;

            if (open < 0) {
                s[i] = '*';
                open = 0;
            }
        }
        int close = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')')
                close++;
            else if (s[i] == '(')
                close--;

            if (close < 0) {
                s[i] = '*';
                close = 0;
            }
        }
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};