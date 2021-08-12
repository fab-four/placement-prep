class Solution {
public:
  // Time Complexity: O(log(n))
  // Space Complexity: O(log(n))
  int monotoneIncreasingDigits(int n) {
    string num = to_string(n);
    int mark = num.size();
    for (int i = num.size() - 1; i > 0; i--) {
      if (num[i - 1] > num[i]) {
        num[i - 1]--;
        mark = i;
      }
    }
    for (int i = mark; i < num.size(); i++) {
      num[i] = '9';
    }
    return stoi(num);
  }
};
