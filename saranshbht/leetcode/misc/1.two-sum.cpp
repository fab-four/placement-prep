/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/two-sum/
 */

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, vector<int>> mp;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      mp[nums[i]].push_back(i);
    }
    for (auto &i : mp) {
      if (mp.count(target - i.first)) {
        if ((target - i.first == i.first)) {
          if (mp[i.first].size() == 1) {
            continue;
          } else {
            res = {mp[i.first][0], mp[i.first][1]};
            break;
          }
        } else {
          res = {mp[i.first][0], mp[target - i.first][0]};
          break;
        }
      }
    }
    return res;
  }
};