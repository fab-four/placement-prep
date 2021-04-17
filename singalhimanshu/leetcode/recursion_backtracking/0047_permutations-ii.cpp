// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/permutations-ii/

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> res;
    solve(0, nums, res);
    return res;
  }

  void solve(int pos, vector<int> nums, vector<vector<int>> &res) {
    if (pos == nums.size()) {
      res.push_back(nums);
    }
    for (int i = pos; i < nums.size(); i++) {
      if (i != pos && nums[i] == nums[pos]) {
        continue;
      }
      swap(nums[i], nums[pos]);
      solve(pos + 1, nums, res);
    }
  }
};
