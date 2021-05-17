/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/perfect-squares/
 */

// BFS
class Solution {
  public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for (int i = 1; i * i <= n; i++) {
            perfectSquares.emplace_back(i * i);
        }
        queue<int> q;
        q.emplace(n);
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();

                for (int i = 0; i < perfectSquares.size() && perfectSquares[i] <= front; i++) {
                    if (front == perfectSquares[i]) {
                        return level;
                    }
                    q.emplace(front - perfectSquares[i]);
                }
            }
        }
        return level;
    }
};

// similar to coin change
class Solution {
  public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for (int i = 1; i * i <= n; i++) {
            perfectSquares.emplace_back(i * i);
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int square : perfectSquares) {
            for (int i = square; i <= n; i++) {
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        return dp[n];
    }
};