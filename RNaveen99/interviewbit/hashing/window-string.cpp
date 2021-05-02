/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/window-string/
 */

string Solution::minWindow(string s, string t) {
    unordered_map<char, int> m;
    for (auto ele : t) {
        m[ele]++;
    }

    int left = 0;
    int right = 0;
    int charCovered = 0;
    int minLen = INT_MAX;
    int minStart;

    while (right < s.length()) {
        m[s[right]]--;

        // expand window
        if (m[s[right]] >= 0) {
            charCovered++;
        }
        right++;

        // shrink window
        while (charCovered == t.length()) {
            if (right - left < minLen) {
                minLen = right - left;
                minStart = left;
            }
            m[s[left]]++;
            if (m[s[left]] > 0) {
                charCovered--;
            }
            left++;
        }
    }
    if (minLen == INT_MAX) {
        return "";
    }

    return s.substr(minStart, minLen);
}
