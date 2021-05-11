/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

// sliding window, hash table, 2 pointers

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        int longest = 0;

        int hash[260] = {0};

        while (start <= end && end < s.length()) {
            hash[s[end]]++;
            if (hash[s[end]] > 1) {
                while (start <= end && hash[s[end]] > 1) {
                    hash[s[start]]--;
                    start++;
                }
            }
            end++;
            longest = max(longest, end - start);
        }
        return longest;
    }
};

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int start = 0;
        int j = 0;
        unordered_map<char, int> m;
        int maxLength = 0;
        while (j < size) {
            if (m.find(s[j]) != m.end() && m[s[j]] >= start) {
                start = m[s[j]] + 1;
            }
            maxLength = max(maxLength, j - start + 1);
            m[s[j]] = j;
            j++;
        }
        return maxLength;
    }
};