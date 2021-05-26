/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/max-points-on-a-line/
 */

class Solution {
  public:
    int maxPoints(vector<vector<int>> &points) {
        int ans = 0;
        map<pair<int, int>, int> slopes;
        for (int i = 0; i < points.size(); i++) {
            slopes.clear();
            int samePoints = 1;
            int localMax = 0;
            for (int j = i + 1; j < points.size(); j++) {
                int xDiff = points[i][0] - points[j][0];
                int yDiff = points[i][1] - points[j][1];
                if (xDiff == yDiff && xDiff == 0) {
                    samePoints++;
                    continue;
                }
                int gcd = __gcd(xDiff, yDiff);
                int x = xDiff / gcd;
                int y = yDiff / gcd;
                slopes[{x, y}]++;
                localMax = max(localMax, slopes[{x, y}]);
            }
            ans = max(ans, localMax + samePoints);
        }
        return ans;
    }
};