/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 */

class Solution {
  public:
    int findMin(vector<int> &nums) { return nums[findMinUtil(nums, 0, nums.size() - 1)]; }

    int findMinUtil(vector<int> &nums, int left, int right) {
        if (left == right)
            return left;
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            return findMinUtil(nums, mid + 1, right);
        } else if (nums[mid] < nums[right]) {
            return findMinUtil(nums, left, mid);
        } else {
            int l = findMinUtil(nums, left, mid);
            int r = findMinUtil(nums, mid + 1, right);
            return nums[l] < nums[r] ? l : r;
        }
    }
};