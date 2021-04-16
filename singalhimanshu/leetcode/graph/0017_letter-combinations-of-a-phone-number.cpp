// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
  const vector<string> key_map = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return {};
    }
    vector<string> res{""};
    for (auto digit : digits) {
      vector<string> temp;
      for (auto neigh : key_map[digit - '0']) {
        for (auto cur_char : res) {
          temp.push_back(cur_char + neigh);
        }
      }
      res = move(temp);
    }
    return res;
  }
};
