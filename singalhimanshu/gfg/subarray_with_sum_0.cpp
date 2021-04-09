// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

class Solution {
public:
  // Complete this function
  // Function to check whether there is a subarray present with 0-sum or not.
  bool subArrayExists(int arr[], int n) {
    int cur_sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
      cur_sum += arr[i];
      if (arr[i] == 0 || cur_sum == 0 || s.count(cur_sum)) {
        return true;
      }
      s.insert(cur_sum);
    }
    return false;
  }
};
