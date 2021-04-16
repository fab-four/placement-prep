/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations;

  public:
    vector<string> letterCombinations(string digits) {
        letterCombinationsUtil(digits, 0, "");
        return combinations;
    }

    void letterCombinationsUtil(string digits, int digitIndex, string combination) {
        if (digits.length() == digitIndex) {
            if (combination.length()) {
                combinations.emplace_back(combination);
            }
            return;
        }
        for (auto ele : digitToChar[digits[digitIndex] - '0']) {
            letterCombinationsUtil(digits, digitIndex + 1, combination + ele);
        }
    }
};