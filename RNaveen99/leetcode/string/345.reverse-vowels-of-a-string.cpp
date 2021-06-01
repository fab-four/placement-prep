/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-vowels-of-a-string/
 */

class Solution {
  public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool isVowel(char c) {
        switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }
};