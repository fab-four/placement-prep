/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   :
 * https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s.insert(0, "I");
    int size = s.size();

    int cnt = 1, dcount;
    for (int i = 0; i < size; i++) {
      int idx = i + 1;
      if (s[i] == 'I' && idx < size && s[idx] == 'D') {
        while (idx < size && s[idx] == 'D') {
          idx++;
          cnt++;
        }
        cout << cnt;
        dcount = cnt - 1;
        cnt++;
      } else if (s[i] == 'D') {
        cout << dcount--;
      } else {
        cout << cnt++;
      }
    }

    cout << endl;
  }

  return 0;
}