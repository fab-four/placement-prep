/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/reorder-data-in-log-files/
 */

int myComparator(pair<string, string> &p1, pair<string, string> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
class Solution {
  public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> ans, digitLogs;
        vector<pair<string, string>> letterLogs;
        for (string log : logs) {
            int i = 0;
            while (log[i] != ' ') {
                i++;
            }
            if (isalpha(log[i + 1])) {
                letterLogs.emplace_back(log.substr(0, i), log.substr(i + 1));
            } else {
                digitLogs.emplace_back(log);
            }
        }
        sort(letterLogs.begin(), letterLogs.end(), myComparator);
        for (auto &p : letterLogs) {
            ans.emplace_back(p.first + " " + p.second);
        }
        for (string &s : digitLogs) {
            ans.emplace_back(s);
        }
        return ans;
    }
};