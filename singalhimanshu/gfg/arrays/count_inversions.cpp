// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/inversion-of-array/0

typedef long long int lli;
typedef long long ll;

class Solution {
public:
  // arr[]: Input Array
  // N : Size of the Array arr[]
  // Function to count inversions in the array.
  long long int inversionCount(long long arr[], long long N) {
    return mergeSort(arr, 0, N - 1);
  }

  lli merge(ll arr[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    lli inv_count = 0;
    ll merged[hi + 1];
    while (i <= mid && j <= hi) {
      if (arr[i] <= arr[j]) {
        merged[k++] = arr[i++];
        continue;
      }
      inv_count += (mid - i + 1);
      merged[k++] = arr[j++];
    }
    while (i <= mid) {
      merged[k++] = arr[i++];
    }
    while (j <= hi) {
      merged[k++] = arr[j++];
    }
    for (int i = lo; i <= hi; i++) {
      arr[i] = merged[i];
    }
    return inv_count;
  }

  lli mergeSort(ll arr[], int lo, int hi) {
    if (lo >= hi) {
      return 0;
    }
    int mid = lo + ((hi - lo) / 2);
    lli inv_count = 0;
    inv_count += mergeSort(arr, lo, mid);
    inv_count += mergeSort(arr, mid + 1, hi);
    inv_count += merge(arr, lo, mid, hi);
    return inv_count;
  }
};
