// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
public:
  vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      pq.push(arr[i]);
    }
    vector<int> result;
    result.reserve(k);
    while (!pq.empty() && k--) {
      result.emplace_back(pq.top());
      pq.pop();
    }
    return result;
  }
};