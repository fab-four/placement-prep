/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {

        vector<int> result(2, -1);
        result[0] = binarySearchLower(nums, target);
        result[1] = binarySearchUpper(nums, target);
        return result;
    }

    int binarySearchLower(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }

    int binarySearchUpper(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }
};