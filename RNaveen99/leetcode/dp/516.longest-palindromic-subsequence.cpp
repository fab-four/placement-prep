/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/longest-palindromic-subsequence/
 */

class Solution {
  public:
    int longestPalindromeSubseq(string s) { return longestPalindromeSubseq(0, s.size() - 1, s); }
    int longestPalindromeSubseq(int l, int r, string &s) {
        if (l == r)
            return 1;
        if (l > r)
            return 0;
        return s[l] == s[r] ? 2 + longestPalindromeSubseq(l + 1, r - 1, s)
                            : max(longestPalindromeSubseq(l + 1, r, s), longestPalindromeSubseq(l, r - 1, s));
    }
};

class Solution {
    vector<vector<int>> pal;

  public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        pal = vector(size, vector<int>(size, false));
        return longestPalindromeSubseq(0, s.size() - 1, s);
    }
    int longestPalindromeSubseq(int l, int r, string &s) {
        if (l == r)
            return 1;
        if (l > r)
            return 0;
        if (pal[l][r])
            return pal[l][r];
        pal[l][r] = s[l] == s[r]
                        ? 2 + longestPalindromeSubseq(l + 1, r - 1, s)
                        : max(longestPalindromeSubseq(l + 1, r, s), longestPalindromeSubseq(l, r - 1, s));
        return pal[l][r];
    }
};

class Solution {
  public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> pal(size, vector<int>(size, 1));

        for (int gap = 0; gap < size; gap++) {
            for (int row = 0, col = gap; col < size; col++, row++) {
                if (gap == 0) {
                    pal[row][col] = 1;
                } else if (gap == 1) {
                    // if end points are same => length = 2
                    // if not then => length = 1
                    if (s[row] == s[col]) {
                        pal[row][col] = 2;
                    }
                } else {
                    // if end points are same => length = 2 + length(mid)
                    // if not then => length = max length including any end point
                    if (s[row] == s[col]) {
                        pal[row][col] = 2 + pal[row + 1][col - 1];
                    } else {
                        pal[row][col] = max(pal[row + 1][col], pal[row][col - 1]);
                    }
                }
            }
        }
        return pal[0][size - 1];
    }
};