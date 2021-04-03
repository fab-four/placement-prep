// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/reorganize-string/

/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
  string reorganizeString(string S) {
    if (S.size() == 0) {
      return S;
    }
    string res = "";
    map<int, int> freq;
    for (const auto &c : S) {
      freq[c]++;
    }
    // {frequency, charcter}
    priority_queue<pair<int, int>> pq;
    for (const auto &ele : freq) {
      if (ele.second > (S.size() + 1) / 2) {
        return res;
      }
      pq.push({ele.second, ele.first});
    }
    while (!pq.empty()) {
      auto most_freq = pq.top();
      pq.pop();
      res += most_freq.second;
      if (!pq.empty()) {
        auto second_most_freq = pq.top();
        pq.pop();
        res += second_most_freq.second;
        if (second_most_freq.first > 1) {
          pq.push({second_most_freq.first - 1, second_most_freq.second});
        }
      }
      if (most_freq.first > 1) {
        pq.push({most_freq.first - 1, most_freq.second});
      }
    }
    return res;
  }
};
// @lc code=end
