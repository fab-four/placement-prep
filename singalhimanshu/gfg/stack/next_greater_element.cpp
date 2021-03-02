// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

vector<long long> nextLargerElement(vector<long long> arr, int n) {
  stack<long long> s;
  s.push(arr[n - 1]);
  vector<long long> spans(n);
  spans[n - 1] = -1;
  for (int i = n - 2; i >= 0; i--) {
    while (!s.empty() && s.top() <= arr[i]) {
      s.pop();
    }
    spans[i] = s.empty() ? -1 : s.top();
    s.push(arr[i]);
  }
  return spans;
}