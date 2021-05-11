/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/intersection-of-two-arrays/
 */

class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> result;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.emplace_back(nums1[i]);
                int left = nums1[i];
                int right = nums2[j];
                while (i < nums1.size() && nums1[i] == left)
                    i++;
                while (j < nums2.size() && nums2[j] == right)
                    j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        return result;
    }
};