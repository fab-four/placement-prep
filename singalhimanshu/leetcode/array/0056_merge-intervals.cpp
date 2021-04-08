// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(begin(intervals), end(intervals));
    vector<vector<int>> result;
    result.push_back({intervals[0]});
    int result_idx = 0;
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= result[result_idx][1]) {
        result[result_idx][1] = max(result[result_idx][1], intervals[i][1]);
        continue;
      }
      result.push_back({intervals[i]});
      result_idx++;
    }
    return result;
  }
};
