/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-sideway-jumps/
 */

class Solution {
    vector<int> lanes = {1, 2, 3};
    vector<vector<int>> dp;

  public:
    int minSideJumps(vector<int> &obstacles) {
        dp.resize(4, vector<int>(obstacles.size(), -1));
        return minSideJumpsUtil(obstacles, 0, 1);
    }

    int minSideJumpsUtil(vector<int> &obstacles, int point, int currentLane) {
        if (point == obstacles.size() - 1)
            return 0;

        if (obstacles[point] == lanes[currentLane])
            return INT_MAX;

        if (dp[lanes[currentLane]][point] != -1)
            return dp[lanes[currentLane]][point];

        if (obstacles[point + 1] != lanes[currentLane]) {
            dp[lanes[currentLane]][point] = minSideJumpsUtil(obstacles, point + 1, currentLane);
        } else {
            int first = minSideJumpsUtil(obstacles, point, (currentLane + 1) % 3);
            int second = minSideJumpsUtil(obstacles, point, (currentLane + 2) % 3);
            dp[lanes[currentLane]][point] = min(first, second) + 1;
        }

        return dp[lanes[currentLane]][point];
    }
};

// dp[i] : minimum jumps to reach lane i
// if meet a stone, set its dp[i] = infinity
// result = min(dp[1:3])

class Solution {
    vector<int> lanes = {1, 2, 3};

  public:
    int minSideJumps(vector<int> &obstacles) {
        vector<int> dp = {0, 1, 0, 1};
        for (int i = 0; i < obstacles.size(); i++) {
            if (obstacles[i]) {
                dp[obstacles[i]] = 1e6;
            }
            for (int laneIndex = 0; laneIndex < 3; laneIndex++) {
                if (obstacles[i] != lanes[laneIndex]) {
                    int current = dp[lanes[laneIndex]];
                    int first = dp[lanes[(laneIndex + 1) % 3]];
                    int second = dp[lanes[(laneIndex + 2) % 3]];

                    dp[lanes[laneIndex]] = min(current, min(first, second) + 1);
                }
            }
        }
        return min({dp[1], dp[2], dp[3]});
    }
};