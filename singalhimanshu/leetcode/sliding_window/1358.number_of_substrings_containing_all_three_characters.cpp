// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  int numberOfSubstrings(string s) {
    int ans = 0;
    int i = 0, j = 0;
    array<int, 3> freq = {0};
    while (j < s.size()) {
      freq[s[j] - 'a']++;
      while (freq[0] && freq[1] && freq[2]) {
        freq[s[i] - 'a']--;
        i++;
      }
      ans += i;
      j++;
    }
    return ans;
  }
};
