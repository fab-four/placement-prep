/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
 */

// dp[n][sum] : # n-digit numbers whose digits on adding equals sum
int rec(vector<vector<int>> &dp, int n, int sum) {
    if (sum < 0)
        return 0;
    if (n == 0 && sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += rec(dp, n - 1, sum - i);
        ans %= 1000000007;
    }
    return dp[n][sum] = ans;
}

int Solution::solve(int A, int B) {
    int ans = 0;
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, -1));
    for (int i = 1; i < 10; i++) {
        ans += rec(dp, A - 1, B - i);
        ans %= 1000000007;
    }
    return ans;
}

// ------------------------------------------------------------------------

int Solution::solve(int n, int sum) {

    int start = pow(10, n - 1);
    int end = pow(10, n) - 1;

    int count = 0;

    while (start <= end) {

        int currSum = 0;
        int num = start;

        while (num) {
            currSum += num % 10;
            num = num / 10;
        }

        if (currSum == sum) {
            count++;
            start += 9;
        } else
            start++;
    }
    return count;
}