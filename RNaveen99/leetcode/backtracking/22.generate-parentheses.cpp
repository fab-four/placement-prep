/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/generate-parentheses/
 */

class Solution {
    vector<string> results;
    string temp;

  public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil(n, 0, 0);
        return results;
    }

    void generateParenthesisUtil(int n, int open, int close) {
        if (open < close)
            return;
        if (open == n && close == n) {
            results.emplace_back(temp);
        }

        if (open < n) {
            temp.push_back('(');
            generateParenthesisUtil(n, open + 1, close);
            temp.pop_back();
        }
        if (close < n) {
            temp.push_back(')');
            generateParenthesisUtil(n, open, close + 1);
            temp.pop_back();
        }
    }
};

class Solution {
    vector<string> results;
    string temp;

  public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil(n, 0, 0);
        return results;
    }

    void generateParenthesisUtil(int n, int open, int close) {
        if (open == n && close == n) {
            results.emplace_back(temp);
        }

        if (open < n) {
            temp.push_back('(');
            generateParenthesisUtil(n, open + 1, close);
            temp.pop_back();
        }
        if (close < open) {
            temp.push_back(')');
            generateParenthesisUtil(n, open, close + 1);
            temp.pop_back();
        }
    }
};