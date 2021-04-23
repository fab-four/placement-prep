// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
  // Time Complexity : O(n)
  // Space Complexity : O(1)
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    vector<int> s_freq(26);
    vector<int> p_freq(26);
    for (char c : p) {
      p_freq[c - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
      s_freq[s[i] - 'a']++;
      if (i >= p.size()) {
        s_freq[s[i - p.size()] - 'a']--;
      }
      if (s_freq == p_freq) {
        res.emplace_back(i - p.size() + 1);
      }
    }
    return res;
  }
};
