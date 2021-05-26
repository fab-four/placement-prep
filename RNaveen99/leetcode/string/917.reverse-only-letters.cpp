/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-only-letters/
 */

class Solution {
  public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        string result(s);
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                i++;
            }
            while (i < j && !isalpha(s[j])) {
                j--;
            }
            if (i < j) {
                result[i] = s[j];
                result[j] = s[i];
            }
            i++;
            j--;
        }
        return result;
    }
};