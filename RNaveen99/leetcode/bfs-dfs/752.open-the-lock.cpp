/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/open-the-lock/
 */

class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        if (visited.find("0000") == visited.end() && visited.find(target) == visited.end()) {
            q.emplace("0000");
        }
        int wheelMoves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string front = q.front();
                q.pop();

                if (front == target) {
                    return wheelMoves;
                }
                vector<string> successors = getSuccessors(front);
                for (string ele : successors) {
                    if (visited.find(ele) == visited.end()) {
                        visited.emplace(ele);
                        q.emplace(ele);
                    }
                }
            }
            wheelMoves++;
        }
        return -1;
    }
    vector<string> getSuccessors(string ele) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            string temp = ele;
            temp[i] = (ele[i] - '0' + 1) % 10 + '0';
            result.emplace_back(temp);

            temp[i] = (ele[i] - '0' + 9) % 10 + '0';
            result.emplace_back(temp);
        }
        return result;
    }
};