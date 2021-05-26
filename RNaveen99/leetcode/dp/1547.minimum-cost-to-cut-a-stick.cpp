/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
 */

// Instead of considering the cost to cut, we can transform the problem to the cost to stick all sticks.
// Add the "cut" index 0 and n, then sort all stick position.
// dp[i][j] means the minimum cost to stick all sticks between cuts[i] and cuts[j]
class Solution {
    vector<vector<int>> dp;

  public:
    int minCost(int n, vector<int> &cuts) {
        dp = vector<vector<int>>(102, vector<int>(102, -1));
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(), cuts.end());
        return minCostUtil(cuts, 0, cuts.size() - 1);
    }

    int minCostUtil(vector<int> &cuts, int start, int end) {
        if (start + 1 == end) {
            return 0;
        }
        if (dp[start][end] > 0) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            int rodLength = cuts[end] - cuts[start];
            int cutCostLeft = minCostUtil(cuts, start, i);
            int cutCostRight = minCostUtil(cuts, i, end);
            ans = min(ans, rodLength + cutCostLeft + cutCostRight);
        }
        ans = ans == INT_MAX ? 0 : ans;
        dp[start][end] = ans;
        return ans;
    }
};

int minCost(int n, vector<int> &A) {
    A.push_back(0);
    A.push_back(n);
    sort(A.begin(), A.end());
    int size = A.size();
    vector<vector<int>> dp(size, vector<int>(size));

    for (int d = 2; d < size; d++) {
        for (int i = 0; i < size - d; i++) {
            dp[i][i + d] = 1e9;
            for (int m = i + 1; m < i + d; m++) {
                dp[i][i + d] = min(dp[i][i + d], dp[i][m] + dp[m][i + d] + A[i + d] - A[i]);
            }
        }
    }
    return dp[0][size - 1];
}