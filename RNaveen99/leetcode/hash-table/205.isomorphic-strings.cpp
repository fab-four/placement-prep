/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/isomorphic-strings/
 */

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> m_s;
        unordered_map<char, char> m_t;

        for (int i = 0; i < s.size(); i++) {
            if (m_s.find(s[i]) == m_s.end() && m_t.find(t[i]) == m_t.end()) {
                m_s[s[i]] = t[i];
                m_t[t[i]] = s[i];
            } else if (m_s.find(s[i]) != m_s.end() && m_t.find(t[i]) != m_t.end()) {
                if (m_s[s[i]] != t[i] || m_t[t[i]] != s[i])
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> m_s;
        unordered_map<char, char> m_t;

        for (int i = 0; i < s.size(); i++) {
            if (m_s.count(s[i]) == 0 && m_t.count(t[i]) == 0) {
                m_s[s[i]] = t[i];
                m_t[t[i]] = s[i];
            } else if (m_s[s[i]] != t[i] || m_t[t[i]] != s[i])
                return false;
        }
        return true;
    }
};

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> m_s(256, -1);
        vector<int> m_t(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (m_s[s[i]] != m_t[t[i]])
                return false;
            m_s[s[i]] = i;
            m_t[t[i]] = i;
        }

        return true;
    }
};