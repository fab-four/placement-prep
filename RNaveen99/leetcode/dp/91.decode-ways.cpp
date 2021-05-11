/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/decode-ways/
 */

class Solution {
  public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i]))
                return 0;

            if (isValid(s[i]))
                dp[i] = dp[i - 1];
            if (isValid(s[i - 1], s[i]))
                dp[i] += i >= 2 ? dp[i - 2] : 1;
        }
        return dp[n - 1];
    }
    bool isValid(char a, char b) { return a == '1' || (a == '2' && b <= '6'); }
    bool isValid(char a) { return a != '0'; }
};

class Solution {
  public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;
        if (n == 1)
            return 1;
        int prev1 = 1, prev2 = 1;
        int num;
        for (int i = 1; i < n; i++) {
            num = 0;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i]))
                return 0;

            if (isValid(s[i]))
                num = prev1;
            if (isValid(s[i - 1], s[i]))
                num += prev2;
            prev2 = prev1;
            prev1 = num;
        }
        return num;
    }
    bool isValid(char a, char b) { return a == '1' || (a == '2' && b <= '6'); }
    bool isValid(char a) { return a != '0'; }
};