// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap/0

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int pos) {
  int left_child_idx = 2 * pos + 1;
  int right_child_idx = left_child_idx + 1;
  int min_idx = pos;
  if (left_child_idx < arr.size() && arr[min_idx] < arr[left_child_idx]) {
    min_idx = left_child_idx;
  }
  if (right_child_idx < arr.size() && arr[min_idx] < arr[right_child_idx]) {
    min_idx = right_child_idx;
  }
  if (min_idx != pos) {
    swap(arr[min_idx], arr[pos]);
    heapify(arr, min_idx);
  }
}

void buildMaxHeap(vector<int> &arr) {
  for (int i = (arr.size() / 2); i >= 0; i--) {
    heapify(arr, i);
  }
}

void print(const vector<int> &arr) {
  for (const auto &ele : arr) {
    cout << ele << ' ';
  }
  cout << '\n';
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + m);
  for (auto &ele : arr) {
    cin >> ele;
  }
  buildMaxHeap(arr);
  print(arr);
}

int main() {
  int test = 0;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
