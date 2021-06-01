/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/happy-number/
 */

class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            int sum = 0;
            while (n) {
                int digit = n % 10;
                sum = sum + digit * digit;
                n = n / 10;
            }
            if (s.find(sum) != s.end()) {
                return false;
            }
            s.emplace(sum);
            n = sum;
        }
        return true;
    }
};