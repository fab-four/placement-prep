class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  bool isHappy(int n) {
    int fast = n, slow = n;
    do {
      slow = transform(slow);
      fast = transform(fast);
      fast = transform(fast);
      if (fast == 1) {
        return true;
      }
    } while (slow != fast);
    return false;
  }

  int transform(int n) {
    int res = 0;
    while (n) {
      int rem = n % 10;
      res += rem * rem;
      n /= 10;
    }
    return res;
  }
};
