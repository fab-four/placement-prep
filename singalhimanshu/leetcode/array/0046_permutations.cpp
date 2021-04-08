// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/permutations/

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> permutations;
    permuteRec(nums, 0, permutations);
    return permutations;
  }

  void permuteRec(vector<int> &nums, int pos, vector<vector<int>> &perms) {
    if (pos == nums.size()) {
      perms.push_back(nums);
      return;
    }
    for (int i = pos; i < nums.size(); i++) {
      swap(nums[i], nums[pos]);
      permuteRec(nums, pos + 1, perms);
      swap(nums[i], nums[pos]);
    }
  }
};
