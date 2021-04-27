/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/occurrences-after-bigram/
 */

class Solution {
  public:
    vector<string> findOcurrences(string text, string first, string second) {
        string prev1, prev2, word;
        stringstream ss(text);
        vector<string> result;
        while (ss >> word) {
            if (prev1 == first && prev2 == second)
                result.emplace_back(word);
            prev1 = prev2;
            prev2 = word;
        }
        return result;
    }
};