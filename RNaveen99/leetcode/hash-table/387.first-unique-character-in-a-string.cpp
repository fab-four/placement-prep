/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/first-unique-character-in-a-string/
 */

class Solution {
  public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        int index = s.size();
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second.first == 1) {
                index = min(index, itr->second.second);
            }
        }
        return index == s.size() ? -1 : index;
    }
};

class Solution {
  public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            count[index]++;
        }

        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            if (count[index] == 1) {
                return i;
            }
        }
        return -1;
    }
};