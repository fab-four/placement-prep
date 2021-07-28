/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/interleaving-string/
 */

class Solution {
    vector<vector<int>> dp;

  public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size()) != s3.size()) {
            return false;
        }
        if (s1.size() == 0) {
            return s2.substr(0) == s3.substr(0) ? true : false;
        }
        if (s2.size() == 0) {
            return s1.substr(0) == s3.substr(0) ? true : false;
        }
        dp = vector<vector<int>>(s1.size(), vector<int>(s2.size(), 0));
        isInterleaveUtil(s1, 0, s2, 0, s3, 0);
        return dp[0][0] == 1 ? true : false;
    }
    int isInterleaveUtil(string &s1, int i, string &s2, int j, string &s3, int k) {
        if (i == s1.size()) {
            return s2.substr(j) == s3.substr(k) ? 1 : -1;
        }
        if (j == s2.size()) {
            return s1.substr(i) == s3.substr(k) ? 1 : -1;
        }
        if (dp[i][j]) {
            return dp[i][j];
        }
        int ans = -1;
        if (i < s1.size() && s1[i] == s3[k]) {
            ans = isInterleaveUtil(s1, i + 1, s2, j, s3, k + 1);
        }
        if ((ans == -1) && j < s2.size() && s2[j] == s3[k]) {
            ans = isInterleaveUtil(s1, i, s2, j + 1, s3, k + 1);
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
};