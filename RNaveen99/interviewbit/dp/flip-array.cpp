/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/flip-array/
 */

// dp[i][j] = optimal solution for filling a knapsack of capacity j
// using elements A[1,2,....,i]
// Optimal solution --> knapsack should be filled upto the capacity using least number of elements
struct node {
    int items;
    int weight;
};

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += A[i];

    // knapsack algorithm for capacity sum/2
    int knapsackCapacity = sum / 2;
    vector<vector<node>> dp(n, vector<node>(knapsackCapacity, {0, 0}));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= knapsackCapacity; j++) {
            if (j >= A[i - 1]) {
                int prev_items = dp[i - 1][j].items;
                int prev_weight = dp[i - 1][j].weight;

                int curr_items = dp[i - 1][j - A[i - 1]].items + 1;
                int curr_weight = dp[i - 1][j - A[i - 1]].weight + A[i - 1];

                if ((curr_weight > prev_weight) ||
                    ((curr_weight == prev_weight) && (curr_items < prev_items))) {
                    dp[i][j] = {curr_items, curr_weight};
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][knapsackCapacity].items;
}