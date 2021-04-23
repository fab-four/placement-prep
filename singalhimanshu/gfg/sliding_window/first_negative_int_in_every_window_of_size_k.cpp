// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/1

typedef long long ll;
typedef long long int lli;

// Time Complexity : O(n)
// Space Complexity : O(n)
vector<ll> printFirstNegativeInteger(lli arr[], lli n, lli k) {
  deque<lli> dq;
  lli i = 0, j = 0;
  vector<ll> res;
  res.reserve(n - k + 1);
  while (j < n) {
    if (arr[j] < 0) {
      dq.push_back(arr[j]);
    }
    if ((j - i + 1) == k) {
      if (dq.empty()) {
        res.emplace_back(0);
      } else {
        res.emplace_back(dq.front());
      }
      if (arr[i] < 0) {
        dq.pop_front();
      }
      i++;
    }
    j++;
  }
  return res;
}
