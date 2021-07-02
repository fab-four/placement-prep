/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/prison-cells-after-n-days/
 */

class Solution {
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        unordered_map<string, int> hash;
        string str = arrayToString(cells);
        while (n > 0) {
            hash[str] = n;
            n--;
            vector<int> cells2(8, 0);
            for (int i = 1; i < 7; i++) {
                cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            cells = cells2;
            str = arrayToString(cells);
            if (hash.count(str)) {
                n = n % (hash[str] - n);
            }
        }
        return cells;
    }
    string arrayToString(vector<int> &cells) {
        string str = "";
        for (int i = 0; i < 8; i++) {
            str += cells[i];
        }
        return str;
    }
};

class Solution {
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        unordered_set<string> hash;
        string str;
        int cycle = 0;
        bool hasCycle = false;
        int j = 0;
        while (j < n) {
            vector<int> nextDayCells = nextDay(cells);
            str = arrayToString(nextDayCells);
            if (hash.count(str)) {
                hasCycle = true;
                break;
            } else {
                hash.emplace(str);
                cycle++;
            }
            j++;
            cells = nextDayCells;
        }
        if (hasCycle) {
            n = n % cycle;
            for (int i = 0; i < n; i++) {
                cells = nextDay(cells);
            }
        }
        return cells;
    }
    string arrayToString(vector<int> &cells) {
        string str = "";
        for (int i = 0; i < 8; i++) {
            str += cells[i];
        }
        return str;
    }
    vector<int> nextDay(vector<int> &cells) {
        vector<int> cells2(8, 0);
        for (int i = 1; i < 7; i++) {
            cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
        }
        return cells2;
    }
};