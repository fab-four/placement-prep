/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/maximum-swap/
 */

class Solution {
  public:
    int maximumSwap(int num) {
        string n = to_string(num);
        int maxIndex = -1;
        int maxDigit = -1;
        int leftIndex = -1;
        int rightIndex = -1;
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n[i] > maxDigit) {
                maxDigit = n[i];
                maxIndex = i;
            } else if (n[i] < maxDigit) {
                leftIndex = i;
                rightIndex = maxIndex;
            }
        }
        if (leftIndex == -1) {
            return num;
        }
        swap(n[leftIndex], n[rightIndex]);
        num = stoi(n);
        return num;
    }
};