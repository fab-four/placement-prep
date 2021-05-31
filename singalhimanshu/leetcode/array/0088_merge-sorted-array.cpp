// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        i--;
      } else {
        nums1[k] = nums2[j];
        j--;
      }
      k--;
    }
  }
};
