/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/can-place-flowers/
 */

// greedy
class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size && n; i++) {
            if (flowerbed[i] == 1)
                continue;
            if (i == 0) {
                if (i + 1 < size && flowerbed[i + 1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                } else if (i + 1 == size) {
                    n--;
                }
            } else if (i == size - 1) {
                if (flowerbed[i - 1] == 0) {
                    n--;
                    flowerbed[i - 1] = 1;
                }
            } else {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n == 0;
    }
};