/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/detect-capital/
 */

class Solution {
  public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        int capitals = 0;
        int i = 0;
        while (i < size) {
            if (isupper(word[i++]))
                capitals++;
        }
        if (capitals == 0 || capitals == size) {
            return true;
        }
        if (capitals == 1 && isupper(word[0])) {
            return true;
        }
        return false;
    }
};