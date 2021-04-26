// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subsets/

class Solution {
public:
  // Time Complexity : O(n * 2^n)
  // Space Complexity : O(n)
  vector<vector<int>> subsets(vector<int> &nums) {
    int subset_count = 1 << nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < subset_count; i++) {
      vector<int> cur;
      for (int j = 0; j < nums.size(); j++) {
        if (i & (1 << j)) {
          cur.emplace_back(nums[j]);
        }
      }
      res.push_back(move(cur));
    }
    return res;
  }
};
