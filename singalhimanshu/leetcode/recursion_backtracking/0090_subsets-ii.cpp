// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> res;
    vector<int> sub;
    solve(0, sub, nums, res);
    return res;
  }
  void solve(int pos, vector<int> &sub, const vector<int> nums,
             vector<vector<int>> &res) {
    res.push_back(sub);
    for (int i = pos; i < nums.size(); i++) {
      if (i > pos && nums[i] == nums[i - 1]) {
        continue;
      }
      sub.emplace_back(nums[i]);
      solve(i + 1, sub, nums, res);
      sub.pop_back();
    }
  }
};
