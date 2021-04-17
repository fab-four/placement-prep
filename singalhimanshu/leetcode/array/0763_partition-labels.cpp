// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/partition-labels/

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> last_pos(26, 0);
    for (int i = 0; i < s.size(); i++) {
      last_pos[s[i] - 'a'] = i;
    }
    vector<int> res;
    int min_pos = -1, part_len = 0;
    for (int i = 0; i < s.size(); i++) {
      min_pos = max(min_pos, last_pos[s[i] - 'a']);
      part_len++;
      if (i == min_pos) {
        res.emplace_back(part_len);
        min_pos = -1;
        part_len = 0;
      }
    }
    return res;
  }
};
