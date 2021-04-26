// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(n)
  int subarraysWithKDistinct(vector<int> &arr, int K) {
    return atmostK(arr, K) - atmostK(arr, K - 1);
  }

  int atmostK(vector<int> &arr, int K) {
    unordered_map<int, int> freq;
    int i = 0, j = 0;
    int res = 0;
    while (j < arr.size()) {
      freq[arr[j]]++;
      if (freq[arr[j]] == 1) {
        K--;
      }
      while (K < 0) {
        freq[arr[i]]--;
        if (freq[arr[i]] == 0) {
          K++;
        }
        i++;
      }
      res += j - i + 1;
      j++;
    }
    return res;
  }
};
