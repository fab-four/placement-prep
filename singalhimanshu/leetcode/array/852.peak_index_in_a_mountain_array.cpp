// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
  // Time Complexity : O(log(n))
  // Space Complexity : O(1)
  int peakIndexInMountainArray(vector<int> &arr) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid != 0 && mid < arr.size() && (arr[mid] > arr[mid - 1]) &&
          (arr[mid] > arr[mid + 1])) {
        return mid;
      }
      if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }
};
