// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int it : nums) {
      if (freq[it]) {
        return true;
      }
      freq[it]++;
    }
    return false;
  }
};
