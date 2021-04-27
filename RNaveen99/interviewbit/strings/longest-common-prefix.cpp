/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/longest-common-prefix/
 */

string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
        return "";
    string ans = "";

    for (int i = 0; i < strs[0].length(); i++) {
        bool isQualified = true;
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                isQualified = false;
                break;
            }
        }
        if (!isQualified)
            break;
        ans.push_back(strs[0][i]);
    }
    return ans;
}