/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/stone-game-iii/
 */

class Solution {
    unordered_map<int, int> m;

  public:
    string stoneGameIII(vector<int> &stoneValue) {
        int result = stoneGameUtil(stoneValue, 0);
        if (result > 0) {
            return "Alice";
        } else if (result < 0) {
            return "Bob";
        }
        return "Tie";
    }
    int stoneGameUtil(vector<int> &stoneValue, int index) {
        if (index >= stoneValue.size()) {
            return 0;
        }
        if (m.count(index)) {
            return m[index];
        }
        int result = stoneValue[index] - stoneGameUtil(stoneValue, index + 1);
        if (index + 1 < stoneValue.size()) {
            result =
                max(result, stoneValue[index] + stoneValue[index + 1] - stoneGameUtil(stoneValue, index + 2));
        }
        if (index + 2 < stoneValue.size()) {
            result = max(result, stoneValue[index] + stoneValue[index + 1] + stoneValue[index + 2] -
                                     stoneGameUtil(stoneValue, index + 3));
        }

        m[index] = result;

        return m[index];
    }
};