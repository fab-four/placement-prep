/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/valid-anagram/
 */

// Two strings are anagrams if and only if their sorted strings are equal.
class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> frequency(26, 0);
        for (char ele : s) {
            frequency[int(ele) - 97]++;
        }
        for (char ele : t) {
            int index = int(ele) - 97;
            frequency[index]--;
            if (frequency[index] < 0) {
                return false;
            }
        }
        return true;
    }
};