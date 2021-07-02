/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/regular-expression-matching/
 */

class Solution {
    unordered_map<string, bool> hash;

  public:
    bool isMatch(string s, string p) { return isMatchUtil(s, 0, p, 0); }

    bool isMatchUtil(string &s, int i, string &p, int j) {
        if (i >= s.size() && j >= p.size()) {
            return true;
        }
        if (j >= p.size()) {
            return false;
        }
        string key = to_string(i) + to_string(j);

        if (hash.count(key)) {
            return hash[key];
        }

        bool match = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
            match = true;
        }
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Don't use * || use * (only when i & j match)
            hash[key] = isMatchUtil(s, i, p, j + 2) || (match && isMatchUtil(s, i + 1, p, j));
        } else if (match) {
            hash[key] = isMatchUtil(s, i + 1, p, j + 1);
        } else {
            hash[key] = false;
        }
        return hash[key];
    }
};

class Solution {

  public:
    bool isMatch(string s, string p) {
        int rows = s.size();
        int cols = p.size();

        vector<vector<bool>> dp(rows + 1, vector<bool>(cols + 1, false));
        dp[0][0] = true;

        for (int c = 1, i = 0; c <= cols; c++, i++) {
            if (p[i] == '*') {
                if (dp[0][c - 1] || (c > 1 && dp[0][c - 2])) {
                    dp[0][c] = true;
                }
            }
        }
        for (int r = 1, i = 0; r <= rows; r++, i++) {
            for (int c = 1, j = 0; c <= cols; c++, j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    dp[r][c] = dp[r - 1][c - 1];
                }
                if (p[j] == '*') {
                    if (s[i] != p[j - 1] && p[j - 1] != '.') {
                        dp[r][c] = dp[r][c - 2];
                    } else {
                        dp[r][c] = dp[r][c - 1] || dp[r - 1][c] || dp[r][c - 2];
                    }
                }
            }
        }
        return dp[rows][cols];
    }
};