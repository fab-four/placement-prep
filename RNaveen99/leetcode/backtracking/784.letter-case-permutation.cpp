/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/letter-case-permutation/
 */

class Solution {
    vector<string> results;

  public:
    vector<string> letterCasePermutation(string S) {
        letterCasePermutationUtil(S, 0);
        return results;
    }

    void letterCasePermutationUtil(string &s, int start) {
        if (start == s.size()) {
            results.emplace_back(s);
            return;
        }
        if (isalpha(s[start])) {
            s[start] = tolower(s[start]);
            letterCasePermutationUtil(s, start + 1);
            s[start] = toupper(s[start]);
            letterCasePermutationUtil(s, start + 1);
        } else {
            letterCasePermutationUtil(s, start + 1);
        }
    }
};

class Solution {
    vector<string> results;

  public:
    vector<string> letterCasePermutation(string S) {
        letterCasePermutationUtil(S, 0);
        return results;
    }

    void letterCasePermutationUtil(string &s, int start) {
        if (start == s.size()) {
            results.emplace_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isalpha(s[i])) {
                s[i] = tolower(s[i]);
                letterCasePermutationUtil(s, i + 1);
                s[i] = toupper(s[i]);
                letterCasePermutationUtil(s, i + 1);
                return;
            } else {
                letterCasePermutationUtil(s, i + 1);
                return;
            }
        }
    }
};