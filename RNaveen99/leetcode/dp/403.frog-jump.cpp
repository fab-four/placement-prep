/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/frog-jump/
 */

class Solution {
    unordered_map<string, bool> dp;

  public:
    bool canCross(vector<int> &stones) { return canCrossUtil(stones, 0, 0); }
    bool canCrossUtil(vector<int> &stones, int index, int jump) {
        string dpIndex = to_string(index) + " " + to_string(jump);

        if (index == (stones.size() - 1)) {
            return dp[dpIndex] = true;
        }
        if (index > (stones.size() - 1)) {
            return false;
        }
        if (dp.count(dpIndex))
            return dp[dpIndex];

        int value = stones[index];
        auto endItr = stones.end();

        auto decreaseJumpItr = lower_bound(stones.begin() + index + 1, stones.end(), value + jump - 1);

        if (isValid(endItr, decreaseJumpItr)) {
            int decreaseJumpIndex = decreaseJumpItr - stones.begin();
            if (stones[decreaseJumpIndex] == (value + jump - 1) &&
                canCrossUtil(stones, decreaseJumpIndex, jump - 1)) {
                return dp[dpIndex] = true;
            }
        }

        auto sameJumpItr = lower_bound(stones.begin() + index + 1, stones.end(), value + jump);

        if (isValid(endItr, sameJumpItr)) {
            int sameJumpIndex = sameJumpItr - stones.begin();
            if (stones[sameJumpIndex] == (value + jump) && canCrossUtil(stones, sameJumpIndex, jump)) {
                return dp[dpIndex] = true;
            }
        }

        auto increaseJumpItr = lower_bound(stones.begin() + index + 1, stones.end(), value + jump + 1);

        if (isValid(endItr, increaseJumpItr)) {
            int increaseJumpIndex = increaseJumpItr - stones.begin();
            if (stones[increaseJumpIndex] == (value + jump + 1) &&
                canCrossUtil(stones, increaseJumpIndex, jump + 1)) {
                return dp[dpIndex] = true;
            }
        }
        return dp[dpIndex] = false;
    }

    bool isValid(vector<int>::iterator itr1, vector<int>::iterator itr2) { return itr1 != itr2; }
};