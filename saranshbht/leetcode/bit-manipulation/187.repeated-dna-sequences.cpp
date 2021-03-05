/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/repeated-dna-sequences/
 */

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    if (n < 10)
      return {};
    map<char, int> char_map;
    char_map['A'] = 0;
    char_map['C'] = 1;
    char_map['G'] = 2;
    char_map['T'] = 3;
    map<int, int> cnt;
    vector<string> res;
    int mask = 0xfffff;
    int key = 0;
    for (int i = 0; i < 10; i++) {
      key = ((key << 2) | char_map[s[i]]);
    }
    cnt[key]++;

    for (int i = 10; i < n; i++) {
      key = (((key << 2) & mask) | char_map[s[i]]);
      if (cnt[key]++ == 1)
        res.push_back(s.substr(i - 9, 10));
    }
    return res;
  }
};