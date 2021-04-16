/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-palindromic-substring/
 */

class Solution {
    int maxLength = -1;
    int startIndex = 0;
    int endingIndex = 0;

  public:
    string longestPalindrome(string s) {
        int size = s.size();

        for (int i = 0; i < size - 1; i++) {
            // for odd length
            extendPalindromeFromCenter(s, i, i);
            // for even length
            extendPalindromeFromCenter(s, i, i + 1);
        }
        return s.substr(startIndex, maxLength);
    }

    void extendPalindromeFromCenter(string &s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }

        if (maxLength < end - start - 1) {
            startIndex = start + 1;
            maxLength = end - start - 1;
        }
    }
};

class Solution {
  public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        int start = 0, len = 0;
        for (int gap = 0; gap < size; gap++) {
            for (int i = 0, j = gap; j < size; i++, j++) {
                if (gap == 0) {
                    // substring of length 1
                    dp[i][j] = true;
                } else if (gap == 1) {
                    // substring of length 2
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                } else {
                    if ((s[i] == s[j]) && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j]) {
                    len = gap;
                    start = i;
                }
            }
        }
        len++;
        return s.substr(start, len);
    }
};