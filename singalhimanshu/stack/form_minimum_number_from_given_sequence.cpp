// @author: Himanshu
// @user: singalhimanshu
// Link: https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void printMinSequence(string sequence) {
  stack<int> stk;
  size_t sequence_size = sequence.size();
  for (size_t i = 0; i <= sequence_size; i++) {
    stk.push(i + 1);
    if (i == sequence_size || sequence[i] == 'I') {
      while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
      }
    }
  }
  cout << '\n';
}

int main() {
  int test;
  cin >> test;
  while (test--) {
    string sequence;
    cin >> sequence;
    printMinSequence(sequence);
  }
  return 0;
}