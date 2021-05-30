/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/partition-labels/
 */

class Solution {
  public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurence(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastOccurence[s[i] - 'a'] = i;
        }
        vector<int> result;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastOccurence[s[i] - 'a']);
            if (i == end) {
                result.emplace_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};