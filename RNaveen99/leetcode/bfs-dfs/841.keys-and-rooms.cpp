/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/keys-and-rooms/
 */

class Solution {
  public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        queue<int> q;
        q.emplace(0);
        int count = 1;
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    q.emplace(key);
                    count++;
                    visited[key] = true;
                }
            }
        }
        return count == rooms.size();
    }
};