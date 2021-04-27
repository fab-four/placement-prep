/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/letter-tile-possibilities/
 */

// counting all the intermediate stages of permutation
class Solution {
    unordered_map<char, int> m;
    int count = 0;

  public:
    int numTilePossibilities(string tiles) {
        for (char ele : tiles) {
            m[ele]++;
        }
        numTileUtil();
        return count;
    }

    void numTileUtil() {
        for (auto &itr : m) {
            if (itr.second > 0) {
                itr.second--;
                count++;
                numTileUtil();
                itr.second++;
            }
        }
    }
};

class Solution {
    int frequency[26];
    int count = 0;

  public:
    int numTilePossibilities(string tiles) {
        for (auto c : tiles) {
            frequency[c - 'A']++;
        }
        numTileUtil();
        return count;
    }

    void numTileUtil() {
        for (int i = 0; i < 26; ++i) {
            if (frequency[i]) {
                frequency[i]--;
                count++;
                numTileUtil();
                frequency[i]++;
            }
        }
    }
};