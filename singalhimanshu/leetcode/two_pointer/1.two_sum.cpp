// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
  // Time Complexity : O(n*log(n))
  // Space Complexity : O(n)
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<pair<int, int>> pv;
    for (int i = 0; i < nums.size(); i++) {
      pv.push_back({nums[i], i});
    }
    sort(begin(pv), end(pv));
    int left_ptr = 0, right_ptr = pv.size() - 1;
    while (left_ptr < right_ptr) {
      int cur_sum = pv[left_ptr].first + pv[right_ptr].first;
      if (cur_sum == target) {
        return {pv[left_ptr].second, pv[right_ptr].second};
      } else if (cur_sum < target) {
        left_ptr++;
      } else {
        right_ptr--;
      }
    }
    return {};
  }
};
