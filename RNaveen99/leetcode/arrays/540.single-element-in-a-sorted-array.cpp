/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/single-element-in-a-sorted-array/
 */

class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
    }
};

class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid & 1) {
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                if (nums[mid] == nums[mid + 1]) {
                    left = mid + 2;
                } else {
                    right = mid;
                }
            }
        }
        return nums[left];
    }
};