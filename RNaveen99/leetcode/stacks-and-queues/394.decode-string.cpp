/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/decode-string/
 */

class Solution {
  public:
    string decodeString(string s) {
        int i = 0;
        return decodeStringUtil(s, i);
    }

    string decodeStringUtil(string &s, int &i) {
        string result;
        int num = 0;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                // now i is at [ ... so skip it
                i++;
                string temp = decodeStringUtil(s, i);
                // now i is at ] ... so skip it
                i++;
                while (num) {
                    result += temp;
                    num--;
                }
            } else {
                result += s[i];
                i++;
            }
        }
        return result;
    }
};

class Solution {
  public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }

    string helper(int &pos, string s) {
        int num = 0;
        string word = "";
        for (; pos < s.size(); pos++) {
            char cur = s[pos];
            if (cur == '[') {
                pos++;
                string curStr = helper(pos, s);
                while (num) {
                    word += curStr;
                    num--;
                }
            } else if (isdigit(cur)) {
                num = num * 10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else { // Normal characters
                word += cur;
            }
        }
        return word;
    }
};

class Solution {
  public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (isalpha(c)) {
                res.push_back(c);
            } else if (c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            } else if (c == ']') {
                string tmp = res;
                for (int i = 0; i < nums.top() - 1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};