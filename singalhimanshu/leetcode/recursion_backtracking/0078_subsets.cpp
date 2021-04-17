// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subsets/

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> sub;
    solve(0, sub, nums, res);
    return res;
  }
  void solve(int pos, vector<int> &sub, const vector<int> nums,
             vector<vector<int>> &res) {
    res.push_back(sub);
    for (int i = pos; i < nums.size(); i++) {
      sub.emplace_back(nums[i]);
      solve(i + 1, sub, nums, res);
      sub.pop_back();
    }
  }
};
