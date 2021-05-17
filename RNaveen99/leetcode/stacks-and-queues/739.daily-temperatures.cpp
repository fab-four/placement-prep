/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/daily-temperatures/
 */

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<int> s;
        s.push(size - 1);
        for (int i = size - 2; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (s.empty())
                result[i] = 0;
            else
                result[i] = s.top() - i;
            s.push(i);
        }
        return result;
    }
};