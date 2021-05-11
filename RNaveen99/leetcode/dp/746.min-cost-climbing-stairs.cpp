/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/min-cost-climbing-stairs/
 */

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        vector<int> minCosts(size + 1, 0);
        for (int i = 2; i <= size; i++) {
            minCosts[i] = min(minCosts[i - 1] + cost[i - 1], minCosts[i - 2] + cost[i - 2]);
        }
        return minCosts[size];
    }
};

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int size = cost.size();
        int first = 0;
        int second = 0;
        for (int i = 2; i <= size; i++) {
            int third = min(first + cost[i - 2], second + cost[i - 1]);
            first = second;
            second = third;
        }
        return second;
    }
};