/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/task-scheduler/
 */

class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> frequency(26, 0);
        int maxFrequency = 0;
        int numberOfMaxFrequency = 0;
        for (char c : tasks) {
            frequency[c - 'A']++;
            if (frequency[c - 'A'] == maxFrequency) {
                numberOfMaxFrequency++;
            } else if (frequency[c - 'A'] > maxFrequency) {
                numberOfMaxFrequency = 1;
                maxFrequency = frequency[c - 'A'];
            }
        }
        int ans = (maxFrequency - 1) * (n + 1);
        ans += numberOfMaxFrequency;
        if (tasks.size() > ans) {
            ans = tasks.size();
        }
        return ans;
    }
};