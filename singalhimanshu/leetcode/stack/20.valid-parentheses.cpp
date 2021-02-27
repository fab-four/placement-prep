// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/valid-parentheses/
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (const auto &word : s) {
      if (isOpenParentheses(word)) {
        st.emplace(word);
      } else if (isClosedParentheses(word)) {
        if (st.empty() || negateParentheses(st.top()) != word) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }

  bool isOpenParentheses(const char &word) {
    return word == '(' || word == '{' || word == '[';
  }

  bool isClosedParentheses(const char &word) {
    return word == ')' || word == '}' || word == ']';
  }

  char negateParentheses(const char &word) {
    if (word == '(') {
      return ')';
    }
    if (word == '{') {
      return '}';
    }
    if (word == '[') {
      return ']';
    }
    return ' ';
  }
};
// @lc code=end
