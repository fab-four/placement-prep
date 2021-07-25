/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2)
            return nums.size();
        int read = 2;
        int write = 2;
        for (; read < nums.size(); read++) {
            if (nums[read] == nums[write - 2]) {
                continue;
            } else {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};