/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/backspace-string-compare/
 */

// stack
class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        buildString(s);
        buildString(t);
        return s == t;
    }
    void buildString(string &s) {
        stack<char> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
            i++;
        }
        s.clear();
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
    }
};

// 2-pointers
class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        s = buildString(s);
        t = buildString(t);
        return s == t;
    }
    string buildString(string &s) {
        int read = 0;
        int write = 0;
        while (read < s.size()) {
            if (s[read] == '#') {
                write--;
                if (write < 0)
                    write = 0;
            } else {
                s[write++] = s[read];
            }
            read++;
        }
        return s.substr(0, write);
    }
};