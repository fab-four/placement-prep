/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/contains-duplicate/
 */

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        return hashSet.size() < nums.size();
    }
};