/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/group-anagrams/
 */

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        if (strs.size() == 0)
            return {{}};
        if (strs.size() == 1)
            return {{strs[0]}};
        vector<pair<string, int>> m;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m.push_back({temp, i});
        }
        sort(m.begin(), m.end());
        vector<vector<string>> result;
        vector<string> anagrams;
        for (int i = 0; i + 1 < m.size(); i++) {
            anagrams.emplace_back(strs[m[i].second]);
            if (m[i].first != m[i + 1].first) {
                result.emplace_back(anagrams);
                anagrams.clear();
            }
        }
        if (m[m.size() - 1].first != m[m.size() - 2].first) {
            anagrams.clear();
        }
        anagrams.emplace_back(strs[m[m.size() - 1].second]);
        result.emplace_back(anagrams);

        return result;
    }
};

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        int i = 0;
        for (string ele : strs) {
            sort(ele.begin(), ele.end());
            m[ele].emplace_back(strs[i++]);
        }

        vector<vector<string>> result;
        for (auto ele : m) {
            result.emplace_back(ele.second);
        }

        return result;
    }
};

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        int i = 0;
        for (string &ele : strs) {
            m[strSort(ele)].emplace_back(ele);
        }

        vector<vector<string>> result;
        for (auto ele : m) {
            result.emplace_back(ele.second);
        }

        return result;
    }
    string strSort(string &s) {
        int n = s.size();
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};