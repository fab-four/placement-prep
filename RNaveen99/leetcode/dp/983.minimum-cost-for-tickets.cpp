/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-cost-for-tickets/
 */

// similar to coin change
class Solution {
  public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        const int totalDays = days[days.size() - 1];
        unordered_set<int> hash(days.begin(), days.end());
        vector<int> dp(totalDays + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= totalDays; i++) {
            if (hash.count(i)) {
                dp[i] = min(dp[max(0, i - 1)] + costs[0], dp[i]);
                dp[i] = min(dp[max(0, i - 7)] + costs[1], dp[i]);
                dp[i] = min(dp[max(0, i - 30)] + costs[2], dp[i]);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[totalDays];
    }
};

// Time: O(n) : # travel days
// Space: (38) : Stricter, it's a sum of duration for all pass types (1 + 7 + 30)
class Solution {
  public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        queue<pair<int, int>> last7Day, last30Day;
        int minCost = 0;
        for (int day : days) {
            while (!last7Day.empty() && last7Day.front().first + 7 <= day) {
                last7Day.pop();
            }
            while (!last30Day.empty() && last30Day.front().first + 30 <= day) {
                last30Day.pop();
            }
            last7Day.push({day, minCost + costs[1]});
            last30Day.push({day, minCost + costs[2]});
            minCost = min({minCost + costs[0], last7Day.front().second, last30Day.front().second});
        }
        return minCost;
    }
};