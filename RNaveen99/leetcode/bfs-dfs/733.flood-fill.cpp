/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/flood-fill/
 */

// similar to number of islands
class Solution {
  public:
    void backtrack(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) {
            return;
        }
        image[sr][sc] = newColor;
        backtrack(image, sr - 1, sc, oldColor, newColor);
        backtrack(image, sr + 1, sc, oldColor, newColor);
        backtrack(image, sr, sc - 1, oldColor, newColor);
        backtrack(image, sr, sc + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            backtrack(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
};