/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/longest-arithmetic-progression/
 */

int Solution::solve(const vector<int> &A) {
    int s = A.size(), ans = 2;
    if (s <= 1)
        return s;
    for (int i = 0; i < s; i++) {
        int first = A[i];
        for (int j = i + 1; j < s; j++) {
            long long last = A[j];
            long long cd = A[j] - A[i];
            int len = 2;
            for (int k = j + 1; k < s; k++) {
                if (A[k] - last == cd) {
                    last = A[k];
                    len++;
                }
            }
            ans = max(ans, len);
        }
    }
    return ans;
}

// a, b, c -> A.P.
// => b - a = c - b
// => 2 * b = a + c
// => 2 * b - c = a
// Here we take i as b and j as c ..... so we find a in map.
int Solution::solve(const vector<int> &arr) {
    int n = arr.size(), ans = 2;
    if (n <= 2) {
        return n;
    }
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ele = 2 * arr[i] - arr[j];
            if (mp.find(ele) != mp.end()) {
                int index = mp[ele];
                dp[i][j] = dp[index][i] + 1;
            }
            ans = max(ans, dp[i][j]);
        }
        mp[arr[i]] = i;
    }
    return ans;
}