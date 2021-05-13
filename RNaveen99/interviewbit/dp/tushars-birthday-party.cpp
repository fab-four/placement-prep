/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/tushars-birthday-party/
 */

// similar to coin change problem
int Solution::solve(vector<int> &friendCapacity, vector<int> &fillingCapacity, vector<int> &cost) {

    int maxCapacity = *max_element(friendCapacity.begin(), friendCapacity.end());

    vector<long> costToFill(maxCapacity + 1, INT_MAX);
    // base case : # cost to fill capacity = 0 is 0.
    costToFill[0] = 0;

    for (int i = 0; i < fillingCapacity.size(); i++) {
        for (int capacity = fillingCapacity[i]; capacity <= maxCapacity; capacity++) {
            costToFill[capacity] =
                min(costToFill[capacity - fillingCapacity[i]] + cost[i], costToFill[capacity]);
        }
    }

    for (auto cap : friendCapacity) {
        costToFill[0] += costToFill[cap];
    }
    return costToFill[0];
}

// ---------------------------------------------------------------------------------------------
#define INF 10000000

int dp[1005][1005];

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // vector of pair {dish_items, dish_cost}
    vector<pair<int, int>> dish;
    int n = C.size();
    for (int i = 0; i < n; i++)
        dish.push_back(make_pair(B[i], C[i]));

    // maximum capacity among friends
    int m = -1;
    for (int i = 0; i < A.size(); i++) {
        m = max(m, A[i]);
    }

    // dp[highest capacity][no. of dishes]
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // if capacity of friend is 0
            if (i == 0)
                dp[i][j] = 0;
            // if no dish is remaining to choose from
            else if (j == 0)
                dp[i][j] = INF;
            else {
                // if i-th person can eat jth dish
                if (i >= dish[j - 1].first) {
                    // As one dish can be taken multiple times, we have used
                    // dp[ i-dish[j-1].first ][ j ] and not dp[ i-dish[j-1].first ][ j-1 ].

                    dp[i][j] = min(dp[i][j - 1], dp[i - dish[j - 1].first][j] + dish[j - 1].second);
                } else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // Add for each friend independently
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        ans += dp[A[i]][n];
    }

    return ans;
}
