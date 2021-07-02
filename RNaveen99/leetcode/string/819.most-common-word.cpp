/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/most-common-word/
 */

class Solution {
  public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> frequency;
        for (auto &c : paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        stringstream ss(paragraph);
        string w;
        string result;
        int count = 0;
        while (ss >> w)
            if (ban.find(w) == ban.end() && ++frequency[w] > count) {
                count++;
                result = w;
            }
        return result;
    }
};