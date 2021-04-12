// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
      set<int> s;
      for (size_t i = 0; i < N; i++) {
          s.insert(arr[i]);
      }
      int ans = 0;
      int cur_max = 0;
      int prev = -1;
      for (const auto &it : s) {
          if (prev == -1) {
              ans++;
              cur_max++;
              prev = it;
              continue;
          }
          cur_max = (prev == it - 1) ? cur_max+1 : 1;
          ans = max(ans, cur_max);
          prev = it;
      }
      return ans;
    }
};
