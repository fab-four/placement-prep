// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

class Solution {
public:
  void merge(int arr1[], int arr2[], int n, int m) {
    // mergeInsertionSort(arr1, arr2, n, m);
    mergeshellSort(arr1, arr2, n, m);
  }

  // Time Complexity: O((n+m)*log(n+m))
  // Space Complexity: O(1)
  void mergeshellSort(int arr1[], int arr2[], int n, int m) {
    int space = (n + m + 1) / 2;
    while (space) {
      int p1 = 0, p2 = space;
      while (p1 < n + m && p2 < n + m) {
        if (p1 < n && p2 >= n && arr1[p1] > arr2[p2 - n]) {
          // p1 - arr1, p2 - arr2
          swap(arr1[p1], arr2[p2 - n]);
        } else if (p1 >= n && arr2[p1 - n] > arr2[p2 - n]) {
          // p1 - arr2, p2 - arr2
          swap(arr2[p1 - n], arr2[p2 - n]);
        } else if (p1 < n && p2 < n && arr1[p1] > arr1[p2]) {
          // p1 - arr1, p2 - arr1
          swap(arr1[p1], arr1[p2]);
        }
        p1 += 1;
        p2 += 1;
      }
      if (space == 1) {
        return;
      }
      space = (space + 1) / 2;
    }
  }

  // Time Complexity: O(n * m)
  // Space Complexity: O(1)
  void mergeInsertionSort(int arr1[], int arr2[], int n, int m) {
    for (int i = 0; i < n; i++) {
      if (arr1[i] <= arr2[0]) {
        continue;
      }
      int j = 0;
      swap(arr1[i], arr2[j]);
      while (j < m - 1 && arr2[j] > arr2[j + 1]) {
        swap(arr2[j], arr2[j + 1]);
        j++;
      }
    }
  }
};
