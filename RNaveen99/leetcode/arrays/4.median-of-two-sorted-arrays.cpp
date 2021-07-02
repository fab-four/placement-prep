/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

// Binary search
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        bool isOdd = (size1 + size2) % 2;
        int left = 0;
        int right = size1;
        while (left <= right) {
            // midX = #elements on left side of X
            // midY = #elements on left side of Y
            int midX = (left + right) / 2;
            int midY = (size1 + size2 + 1) / 2 - midX;

            int maxLeftX = (midX == 0) ? INT_MIN : nums1[midX - 1];
            int minRightX = (midX == size1) ? INT_MAX : nums1[midX];

            int maxLeftY = (midY == 0) ? INT_MIN : nums2[midY - 1];
            int minRightY = (midY == size2) ? INT_MAX : nums2[midY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if (isOdd) {
                    return (double)max(maxLeftX, maxLeftY);
                } else {
                    return ((double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2);
                }
            } else if (maxLeftX > minRightY) {
                // decrease #elemens on left side of X
                right = midX - 1;
            } else {
                // increase #elemens on left side of X
                left = midX + 1;
            }
        }
        return -1;
    }
};