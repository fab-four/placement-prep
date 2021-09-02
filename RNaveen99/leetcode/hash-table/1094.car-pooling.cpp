/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/car-pooling/
 */

// similar to Meeting Rooms
class Solution {
  public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        // stop, passengers
        map<int, int> m;
        for (auto &ele : trips) {
            m[ele[1]] += ele[0];
            m[ele[2]] -= ele[0];
        }
        for (auto &ele : m) {
            capacity -= ele.second;
            if (capacity < 0)
                return false;
        }
        return true;
    }
};