// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/majority-element/

class Solution {
public:
  // Moore's Voting Algorithm
  int majorityElement(vector<int> &nums) {
    int majority_ele = 0;
    int count = 0;
    for (const auto &ele : nums) {
      if (count == 0) {
        majority_ele = ele;
        count++;
      } else if (ele == majority_ele) {
        count++;
      } else {
        count--;
      }
    }
    return majority_ele;
  }
};
