/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/next-greater-element-iii/
 */

class Solution {
  public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while (n) {
            digits.emplace_back(n % 10);
            n = n / 10;
        }
        reverse(digits.begin(), digits.end());
        int i = digits.size() - 2;
        for (; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                break;
            }
        }
        if (i == -1)
            return -1;
        int j = digits.size() - 1;
        for (; j >= i; j--) {
            if (digits[j] > digits[i]) {
                break;
            }
        }
        swap(digits[i], digits[j]);
        reverse(digits.begin() + i + 1, digits.end());
        for (i = 0; i < digits.size(); i++) {
            if (n > INT_MAX / 10 || n == INT_MAX / 10 && digits[i] > 7) {
                return -1;
            }
            n = n * 10 + digits[i];
        }
        return n;
    }
};