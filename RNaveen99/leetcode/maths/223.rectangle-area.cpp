/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/rectangle-area/
 */

class Solution {
  public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfSqrA = (ax2 - ax1) * (ay2 - ay1);
        int areaOfSqrB = (bx2 - bx1) * (by2 - by1);

        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int bottom = max(ay1, by1);
        int top = min(ay2, by2);

        // If overlap
        int overlap = 0;
        if (right > left && top > bottom)
            overlap = (right - left) * (top - bottom);

        return areaOfSqrA + areaOfSqrB - overlap;
    }
};