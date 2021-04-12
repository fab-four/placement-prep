// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

constexpr int mmin = numeric_limits<int>::min();
constexpr int mmax = numeric_limits<int>::max();

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    auto n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int low = 0, high = n1;
    while (low <= high) {
      int split_x = (low + high) / 2;
      int split_y = (n1 + n2 + 1) / 2 - split_x;

      int max_left_x = (split_x == 0) ? mmin : nums1[split_x - 1];
      int min_right_x = (split_x == n1) ? mmax : nums1[split_x];

      int max_left_y = (split_y == 0) ? mmin : nums2[split_y - 1];
      int min_right_y = (split_y == n2) ? mmax : nums2[split_y];

      if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
        if ((n1 + n2) & 1) {
          return max(max_left_x, max_left_y);
        }
        cout << "max_left_x: " << max_left_x << ", min_right_y: " << min_right_y
             << '\n';
        cout << "max_left_y: " << max_left_y << ", min_right_x: " << min_right_x
             << '\n';
        double max_left = max(max_left_x, max_left_y);
        double min_right = min(min_right_x, min_right_y);
        return (max_left + min_right) / 2;
      } else if (max_left_x > min_right_y) {
        high = split_x - 1;
      } else {
        low = split_x + 1;
      }
    }
    return 0;
  }
};
