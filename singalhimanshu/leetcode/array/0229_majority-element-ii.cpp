// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int count1 = 0, count2 = 0;
    int maj1 = 0, maj2 = 0;
    for (const auto &ele : nums) {
      if (maj1 == ele) {
        count1++;
      } else if (maj2 == ele) {
        count2++;
      } else if (count1 == 0) {
        maj1 = ele;
        count1++;
      } else if (count2 == 0) {
        maj2 = ele;
        count2++;
      } else {
        count1--;
        count2--;
      }
    }
    if (maj1 == maj2) {
      return {maj1};
    }
    count1 = count2 = 0;
    for (const auto &ele : nums) {
      if (ele == maj1) {
        count1++;
      }
      if (ele == maj2) {
        count2++;
      }
    }
    vector<int> majority_result;
    if (count1 > (nums.size() / 3)) {
      majority_result.emplace_back(maj1);
    }
    if (count2 > (nums.size() / 3)) {
      majority_result.emplace_back(maj2);
    }
    return majority_result;
  }
};
