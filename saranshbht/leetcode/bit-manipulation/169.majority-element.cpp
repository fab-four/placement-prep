/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/majority-element/
 */

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int &i : nums) {
      if (++mp[i] > (n >> 1))
        return i;
    }
    return -1;

    //         Boyer-Moore Majority Voting
    //         int count = 1, major = nums[0];
    //         int n = nums.size();
    //         for (int i = 1; i < n; i++) {
    //             if (!count) {
    //                 major = nums[i];
    //                 count++;
    //             }
    //             else if (nums[i] == major)
    //                 count++;
    //             else
    //                 count--;
    //         }
    //         return major;
  }
};