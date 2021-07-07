/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/rectangle-overlap/
 */

class Solution {
  public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        // check if either rectangle is actually a line
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            // the line cannot have positive overlap
            return false;
        }

        return !(rec1[2] <= rec2[0] || // left
                 rec1[3] <= rec2[1] || // bottom
                 rec1[0] >= rec2[2] || // right
                 rec1[1] >= rec2[3]);  // top
    }
};

class Solution {
  public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        int left = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);
        int top = min(rec1[3], rec2[3]);
        int bottom = max(rec1[1], rec2[1]);

        return (right > left) && (top > bottom);
    }
};