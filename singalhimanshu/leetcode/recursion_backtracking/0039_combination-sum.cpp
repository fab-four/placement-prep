// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(begin(candidates), end(candidates));
    vector<vector<int>> res;
    vector<int> temp;
    solve(0, temp, candidates, target, res);
    return res;
  }

  void solve(int idx, vector<int> &cur_selection, const vector<int> &candidates,
             int target, vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(cur_selection);
      return;
    }
    if (idx >= candidates.size()) {
      return;
    }
    for (int i = idx; i < candidates.size() && (target >= candidates[i]); i++) {
      cur_selection.emplace_back(candidates[i]);
      solve(i, cur_selection, candidates, target - candidates[i], res);
      cur_selection.pop_back();
    }
  }
};
