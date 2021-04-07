// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

class Solution {
public:
  int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int result = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] >= k) {
        int cur_min = min(arr[i] - k, arr[0] + k);
        int cur_max = max(arr[i - 1] + k, arr[n - 1] - k);
        result = min(result, cur_max - cur_min);
      }
    }
    return result;
  }
};
