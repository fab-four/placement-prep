/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
    vector<vector<string>> results;
    vector<string> temp;

  public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        partitionUtil(s, dp, 0);
        return results;
    }

    void partitionUtil(string &s, vector<vector<bool>> &dp, int start) {
        if (start >= s.size()) {
            results.emplace_back(temp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (s[start] == s[i] && ((i - start <= 2) || dp[start + 1][i - 1])) {
                dp[start][i] = true;
                temp.emplace_back(s.substr(start, i - start + 1));
                partitionUtil(s, dp, i + 1);
                temp.pop_back();
            }
        }
    }
};

class Solution {
    vector<vector<string>> results;
    vector<string> temp;

  public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int gap = 0; gap < s.size(); gap++) {
            for (int row = 0, col = gap; col < s.size(); row++, col++) {
                if (gap == 0) {
                    dp[row][col] = true;
                } else if (gap == 1) {
                    if (s[row] == s[col]) {
                        dp[row][col] = true;
                    }
                } else {
                    if (dp[row + 1][col - 1] && s[row] == s[col]) {
                        dp[row][col] = true;
                    }
                }
            }
        }
        partitionUtil(s, dp, 0);
        return results;
    }

    void partitionUtil(string &s, vector<vector<bool>> &dp, int start) {
        if (start >= s.size()) {
            results.emplace_back(temp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {
                temp.emplace_back(s.substr(start, i - start + 1));
                partitionUtil(s, dp, i + 1);
                temp.pop_back();
            }
        }
    }
};