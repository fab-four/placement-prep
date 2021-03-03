// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
public:
  int celebrity(vector<vector<int>> &M, int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
      s.push(i);
    }
    while (s.size() >= 2) {
      int top1 = s.top();
      s.pop();
      int top2 = s.top();
      s.pop();
      if (M[top1][top2]) {
        s.push(top2);
      } else {
        s.push(top1);
      }
    }
    if (s.empty()) {
      return -1;
    }
    int possible_celeb = s.top();
    s.pop();
    for (int i = 0; i < n; i++) {
      if (i != possible_celeb) {
        if (M[possible_celeb][i] || M[i][possible_celeb] == 0) {
          return -1;
        }
      }
    }
    return possible_celeb;
  }
};