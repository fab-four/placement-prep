/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-words-in-a-string-iii/
 */

class Solution {
  public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                int j;
                for (j = i; j < s.size() && s[j] != ' '; j++)
                    ;
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};