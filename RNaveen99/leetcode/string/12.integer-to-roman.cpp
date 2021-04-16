/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/integer-to-roman/
 */

class Solution {
  public:
    string intToRoman(int num) {
        vector<string> roman = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                "XL", "X",  "IX", "V",  "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string answer = "";
        int i = 0;
        while (num > 0) {
            if (num >= values[i]) {
                answer += roman[i];
                num -= values[i];
            } else {
                i++;
            }
        }

        return answer;
    }
};

class Solution {
  public:
    string intToRoman(int num) {
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> M = {"", "M", "MM", "MMM"};

        string roman = "";
        roman += M[num / 1000];
        num = num % 1000;

        roman += C[num / 100];
        num = num % 100;

        roman += X[num / 10];
        num = num % 10;

        roman += I[num % 10];

        return roman;
    }
};