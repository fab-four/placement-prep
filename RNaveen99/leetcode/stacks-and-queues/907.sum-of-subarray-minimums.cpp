/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/sum-of-subarray-minimums/
 */

// leftDistance : size of subarray in which arr[i] is minimum element till i from 0
class Solution {
    long mod = 1e9 + 7;

  public:
    int sumSubarrayMins(vector<int> &arr) {
        int size = arr.size();
        vector<int> leftDistance(size, 1), rightDistance(size, 1);
        stack<int> s;
        for (int i = 0; i < size; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                leftDistance[i] = i + 1;
            } else {
                leftDistance[i] = i - s.top();
            }
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        for (int i = size - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                rightDistance[i] = size - i;
            } else {
                rightDistance[i] = s.top() - i;
            }
            s.push(i);
        }
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum = (sum + ((arr[i] * leftDistance[i]) % mod * rightDistance[i]) % mod) % mod;
        }
        return sum;
    }
};