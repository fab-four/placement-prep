/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/remove-outermost-parentheses/
 */

// similar to https://www.interviewbit.com/problems/redundant-braces/

class Solution {
  public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int close = 0;
        string result;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                result += s.substr(i - open - close + 2, open + close - 2);
                open = close = 0;
            }
            i++;
        }
        return result;
    }
};