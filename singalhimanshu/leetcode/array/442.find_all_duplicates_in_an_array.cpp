// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> res;
    res.reserve(nums.size() / 2);
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i] >= 0 ? nums[i] : -nums[i];
      if (nums[temp - 1] < 0) {
        res.emplace_back(temp);
      }
      nums[temp - 1] *= -1;
    }
    return res;
  }
};
