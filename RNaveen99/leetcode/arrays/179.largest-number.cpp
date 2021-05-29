/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/largest-number/
 */

bool myComparator(string &a, string &b) { return (a + b) > (b + a); }
class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        vector<string> result;
        for (int ele : nums) {
            result.emplace_back(to_string(ele));
        }
        sort(result.begin(), result.end(), myComparator);
        string ans;
        if (result[0] == "0")
            return "0";
        for (string ele : result) {
            ans += ele;
        }
        return ans;
    }
};