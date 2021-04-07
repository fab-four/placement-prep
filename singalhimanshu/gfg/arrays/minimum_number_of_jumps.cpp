// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

class Solution {
public:
  int minJumps(int arr[], int n) {
    int cur_max_reach = 0, jumps = 0, cur_reach = 0;
    for (int i = 0; i < n - 1; i++) {
      cur_max_reach = max(cur_max_reach, i + arr[i]);
      if (i == cur_reach) {
        jumps++;
        cur_reach = cur_max_reach;
      }
      if (cur_reach >= n - 1) {
        return jumps;
      }
    }
    return -1;
  }
};
