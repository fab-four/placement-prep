/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/permutation-sequence/
 */

class Solution {

  public:
    string getPermutation(int n, int k) {
        string answer = "";
        set<int> numbers;
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
            numbers.emplace(i);
        }
        k--;
        int eachNumberPermutations = 0;
        for (int i = n; i >= 1; i--) {
            eachNumberPermutations = fact / i;

            int numbersCovered = k / eachNumberPermutations;

            k = k - eachNumberPermutations * numbersCovered;

            int num = *next(numbers.begin(), numbersCovered);
            numbers.erase(num);

            answer += to_string(num);
            fact = fact / i;
        }
        return answer;
    }
};