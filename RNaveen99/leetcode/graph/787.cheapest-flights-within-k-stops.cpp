/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        const int INF = 1e9;
        // Note: K Stops = K + 1 edges
        vector<vector<int>> dp(K + 2, vector<int>(n, INF));
        // dp[i][j] = Distance to reach j using atmost i edges from src
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; ++i) {
            dp[i][src] = 0;
            for (const auto &x : flights) {
                int s = x[0];
                int d = x[1];
                int cost = x[2];
                dp[i][d] = min(dp[i][d], dp[i - 1][s] + cost);
            }
        }
        return dp[K + 1][dst] >= INF ? -1 : dp[K + 1][dst];
    }
};