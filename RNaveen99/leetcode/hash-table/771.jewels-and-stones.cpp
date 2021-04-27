/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/jewels-and-stones/
 */

class Solution {
  public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> result(52, 0);
        int count = 0, offset = 26;
        for (int i = 0; i < jewels.size(); i++) {
            if (isupper(jewels[i])) {
                result[jewels[i] - 'A'] = 1;
            } else {
                result[jewels[i] - 'a' + offset] = 1;
            }
        }
        for (int i = 0; i < stones.size(); i++) {
            if (isupper(stones[i])) {
                if (result[stones[i] - 'A'])
                    count++;
            } else {
                if (result[stones[i] - 'a' + offset])
                    count++;
            }
        }

        return count;
    }
};

class Solution {
  public:
    int numJewelsInStones(string J, string S) {
        vector<int> exists('z' + 1, 0);

        for (auto &ele : J) {
            exists[ele] = 1;
        }
        int count = 0;
        for (auto &ele : S) {
            if (exists[ele]) {
                count++;
            }
        }
        return count;
    }
};