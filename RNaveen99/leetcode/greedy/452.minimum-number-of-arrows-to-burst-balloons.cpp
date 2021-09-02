/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        // sort by ending position
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2) { return p1[1] < p2[1]; });

        int arrows = 1;
        int index = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[index][1] >= points[i][0]) {
                // overlapping interval ... do nothing
            } else {
                arrows++;
                index = i;
            }
        }
        return arrows;
    }
};