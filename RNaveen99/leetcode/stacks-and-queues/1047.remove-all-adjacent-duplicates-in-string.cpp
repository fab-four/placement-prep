/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 */

class Solution {
  public:
    string removeDuplicates(string s) {
        deque<char> dq;
        int i = 0;
        dq.emplace_back(s[i++]);
        while (i < s.size()) {
            if (!dq.empty() && s[i] == dq.back())
                dq.pop_back();
            else
                dq.emplace_back(s[i]);
            i++;
        }
        string result;
        while (!dq.empty()) {
            result += dq.front();
            dq.pop_front();
        }
        return result;
    }
};

class Solution {
  public:
    string removeDuplicates(string s) {
        string result;
        int i = 0;
        result.push_back(s[i++]);
        while (i < s.size()) {
            if (!result.empty() && s[i] == result.back())
                result.pop_back();
            else
                result.push_back(s[i]);
            i++;
        }
        return result;
    }
};