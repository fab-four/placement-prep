// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

class Solution {
public:
  int findPages(int arr[], int n, int m) {
    if (m > n) {
      return -1;
    }
    int sum = accumulate(arr, arr + n, 0);
    int max_ele = *max_element(arr, arr + n);
    int low = max_ele, high = sum;
    int ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (isValid(arr, n, m, mid)) {
        high = mid - 1;
        ans = mid;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }

  bool isValid(int arr[], int n, int m, int max_sum) {
    int students_req = 1;
    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
      cur_sum += arr[i];
      if (cur_sum > max_sum) {
        students_req++;
        cur_sum = arr[i];
      }
      if (students_req > m) {
        return false;
      }
    }
    return true;
  }
};
