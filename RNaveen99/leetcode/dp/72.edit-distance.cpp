/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/edit-distance/
 */

// string alignment
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int rows = word1.length();
        int columns = word2.length();
        vector<vector<int>> dp(rows + 1, vector<int>(columns + 1));

        for (int i = 0; i <= rows; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= columns; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= columns; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[rows][columns];
    }
};

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            pre[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre[j - 1];
                } else {
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pre[n];
    }
};

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};