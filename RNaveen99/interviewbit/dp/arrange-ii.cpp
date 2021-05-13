/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/arrange-ii/
 */

// dp[i][j] : value of accommodating (N-i) horses in (K-j) stables
// so we return dp[0][0] : value of accommodating (N - 0 => N) horses in (K - j => K) stables
vector<vector<int>> dp;

int rec(int start, int stables, string &str, int totalStables) {
    int size = str.size();
    if (start == size) {
        if (stables == totalStables)
            return 0;
        return INT_MAX;
    }

    if (stables == totalStables)
        return INT_MAX;

    if (dp[start][stables] != -1)
        return dp[start][stables];

    int W = 0;
    int B = 0;
    int ans = INT_MAX;

    for (int i = start; i < size; i++) {
        W += str[i] == 'W';
        B += str[i] == 'B';

        // pruning
        // because the number of whites/black will only increase => increase in product
        // continue will work fine too.
        // even removing this statement will work fine too.
        if (W * B > ans)
            break;

        int temp = rec(i + 1, stables + 1, str, totalStables);

        // overflow
        if (temp != INT_MAX) {
            ans = min(ans, temp + (W * B));
        }
    }
    dp[start][stables] = ans;
    return dp[start][stables];
}

int Solution::arrange(string str, int K) {
    int size = str.size();
    dp.clear();
    dp.resize(size, vector<int>(K, -1));

    int ans = rec(0, 0, str, K);
    return ans == INT_MAX ? -1 : ans;
}

// --------------------------------------------------------------------------

// dp[i][j] : value of accommodating (N-i) horses in j stables
// so we return dp[0][stables-1] : value of accommodating (N - 0 => N) horses in j stables
vector<vector<int>> dp;

int rec(int start, int stables, string &str) {
    int size = str.size();
    if (start == size) {
        if (stables == 0)
            return 0;
        return INT_MAX;
    }

    if (stables == 0)
        return INT_MAX;

    if (dp[start][stables - 1] != -1)
        return dp[start][stables - 1];

    int W = 0;
    int B = 0;
    int ans = INT_MAX;

    for (int i = start; i < size; i++) {
        W += str[i] == 'W';
        B += str[i] == 'B';

        if (W * B > ans)
            break;

        int temp = rec(i + 1, stables - 1, str);

        // overflow
        if (temp != INT_MAX) {
            ans = min(ans, temp + (W * B));
        }
    }
    dp[start][stables - 1] = ans;
    return dp[start][stables - 1];
}

int Solution::arrange(string str, int K) {
    int size = str.size();
    dp.clear();
    dp.resize(size, vector<int>(K, -1));

    int ans = rec(0, K, str);
    return ans == INT_MAX ? -1 : ans;
}

// ------------------------------------------------------------------------------------
vector<vector<int>> dp;

int rec(int start, int stables, string &str) {
    int size = str.size();
    if (start == size) {
        if (stables == 0)
            return 0;
        return INT_MAX;
    }

    if (stables == 0)
        return INT_MAX;

    if (dp[start][stables] != -1)
        return dp[start][stables];

    int W = 0;
    int B = 0;
    int ans = INT_MAX;

    for (int i = start; i < size; i++) {
        W += str[i] == 'W';
        B += str[i] == 'B';
        if (W * B > ans)
            break;

        int temp = rec(i + 1, stables - 1, str);

        // overflow
        if (temp != INT_MAX) {
            ans = min(ans, temp + (W * B));
        }
    }
    dp[start][stables] = ans;
    return dp[start][stables];
}

int Solution::arrange(string str, int K) {
    int size = str.size();
    dp.clear();
    dp.resize(size, vector<int>(K + 1, -1));

    int ans = rec(0, K, str);
    return ans == INT_MAX ? -1 : ans;
}