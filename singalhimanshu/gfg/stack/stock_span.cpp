// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

vector<int> calculateSpan(int price[], int n) {
  vector<int> spans{n};
  stack<int> s;
  s.push(0);
  spans[0] = 1;
  for (int i = 1; i < n; i++) {
    while (!s.empty() && price[s.top()] < price[i]) {
      s.pop();
    }
    int span = s.empty() ? (i + 1) : (i - s.top());
    spans[i] = span;
    s.push(i);
  }
  return spans;
}