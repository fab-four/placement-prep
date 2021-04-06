// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

class Solution {
public:
  void sort012(int a[], int n) {
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi) {
      switch (a[mid]) {
      case 0:
        swap(a[lo], a[mid]);
        lo++;
        mid++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        swap(a[hi], a[mid]);
        hi--;
        break;
      }
    }
  }
};
