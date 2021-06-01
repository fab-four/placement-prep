/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/flipping-an-image/
 */

class Solution {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        int rows = image.size();
        int cols = image[0].size();

        for (int r = 0; r < rows; r++) {
            int left = 0;
            int right = cols - 1;
            while (left <= right) {
                int temp = image[r][right];
                image[r][right] = image[r][left] ^ 1;
                image[r][left] = temp ^ 1;
                left++;
                right--;
            }
        }
        return image;
    }
};