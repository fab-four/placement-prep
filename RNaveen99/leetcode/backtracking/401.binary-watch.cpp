/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-watch/
 */

class Solution {
  public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (bitset<10>(h << 6 | m).count() == turnedOn)
                    result.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
        return result;
    }
};

class Solution {
    vector<string> result;

  public:
    vector<string> readBinaryWatch(int turnedOn) {
        string s = "0000000000";
        readBinaryWatchUtil(s, turnedOn, 0);
        return result;
    }
    void readBinaryWatchUtil(string &s, int turnedOn, int start) {
        int hours = std::bitset<4>(s.substr(6, 4)).to_ulong();
        if (hours > 11) {
            return;
        }
        int minutes = std::bitset<6>(s.substr(0, 6)).to_ulong();
        if (minutes > 59) {
            return;
        }
        if (turnedOn == 0) {
            result.push_back(to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes));
            return;
        }

        for (int i = start; i < s.size(); i++) {
            s[i] = '1';
            readBinaryWatchUtil(s, turnedOn - 1, i + 1);
            s[i] = '0';
        }
    }
};