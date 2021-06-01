/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reverse-string/
 */

class Solution {
  public:
    void reverseString(vector<char> &s) { reverseStringUtil(s, 0, s.size() - 1); }
    void reverseStringUtil(vector<char> &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};