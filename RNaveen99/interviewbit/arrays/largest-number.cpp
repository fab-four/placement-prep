/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/largest-number/
 */

bool comparator(string a, string b) { return a + b > b + a; }

string Solution::largestNumber(const vector<int> &A) {
    vector<string> nums;
    for (auto it : A) {
        nums.push_back(to_string(it));
    }
    sort(nums.begin(), nums.end(), comparator);
    string res = "";
    for (auto it : nums) {
        res += it;
    }

    if (res[0] == '0') {
        res = '0';
    }

    return res;
}