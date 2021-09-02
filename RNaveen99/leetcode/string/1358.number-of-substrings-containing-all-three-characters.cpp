/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 */

// sliding window
class Solution {
  public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};
        int result = 0;
        int start = 0;
        int size = s.length();
        for (int end = 0; end < size; end++) {
            count[s[end] - 'a']++;
            while (count[0] && count[1] && count[2])
                --count[s[start++] - 'a'];
            result += start;
        }
        return result;
    }
};