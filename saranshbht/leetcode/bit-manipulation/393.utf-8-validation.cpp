/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/utf-8-validation/
 */

class Solution {
public:
  bool validUtf8(vector<int> &data) {
    // on encountering the starting byte for n-bytes character, check if
    // subsequent n - 1 bytes start with "10" else check if the byte starts with
    // "0"
    int cnt = 0;
    for (auto &i : data) {
      if (cnt) {
        if ((i >> 6) != 0b10)
          return false;
        cnt--;
      } else {
        if ((i >> 5) == 0b110)
          cnt = 1;
        else if ((i >> 4) == 0b1110)
          cnt = 2;
        else if ((i >> 3) == 0b11110)
          cnt = 3;
        else if ((i >> 7))
          return false;
      }
    }
    return cnt == 0;
  }
};