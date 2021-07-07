/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-all-anagrams-in-a-string/
 */

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int size = 26;

        vector<int> frequencyS(size, 0);
        vector<int> frequencyP(size, 0);
        vector<int> result;

        if (s.size() < p.size()) {
            return result;
        }

        for (int i = 0; i < p.size(); i++) {
            frequencyS[s[i] - 'a']++;
            frequencyP[p[i] - 'a']++;
        }
        if (frequencyS == frequencyP) {
            result.emplace_back(0);
        }
        for (int i = p.size(); i < s.size(); i++) {
            frequencyS[s[i] - 'a']++;
            frequencyS[s[i - p.size()] - 'a']--;

            if (frequencyS == frequencyP) {
                result.emplace_back(i - p.size() + 1);
            }
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        unordered_set<string> hash;
        hash.emplace(sortString(p));
        vector<int> result;
        for (int i = 0; (i + p.size() - 1) < s.size(); i++) {
            if (hash.count(sortString(s.substr(i, p.size())))) {
                result.emplace_back(i);
            }
        }
        return result;
    }

    string sortString(string p) {
        string temp = "";
        int size = 26;
        vector<int> frequency(size, 0);
        for (char c : p) {
            frequency[c - 'a']++;
        }
        for (int i = 0; i < size; i++) {
            if (frequency[i]) {
                char c = (char)('a' + i);
                temp += c + to_string(frequency[i]);
            }
        }
        return temp;
    }
};