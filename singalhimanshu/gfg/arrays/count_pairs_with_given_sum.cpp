// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution {
public:
  int getPairsCount(int arr[], int n, int k) {
    map<int, int> freq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (freq[k - arr[i]]) {
        ans += freq[k - arr[i]];
      }
      freq[arr[i]]++;
    }
    return ans;
  }
};
