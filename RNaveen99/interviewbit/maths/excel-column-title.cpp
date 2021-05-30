/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/excel-column-title/
 */

class Solution {
  public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            n--;
            res.push_back((n % 26) + 'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// The problem is similar to converting a decimal number to its binary representation but instead of a binary
// base system where we have two digits only 0 and 1, here we have 26 characters from A-Z.
// So, we are dealing with base 26 instead of base binary.

// We don’t have zero in this number system, as A represents 1, B represents 2 and so on Z represents 26. To
// make the problem easily understandable, we approach the problem in two steps:

// Convert the number to base 26 representation, considering we have 0 also in the system.
// Change the representation to the one without having 0 in its system.

// In Base 26 Number System to deal with zero, we borrow 26 and subtract 1 from the next significant bit.

string Solution::convertToTitle(int A) {
    vector<int> arr;
    int i = 0;
    while (A) {
        arr.push_back(A % 26);
        A = A / 26;
        i++;
    }
    for (int j = 0; j + 1 < arr.size(); j++) {
        if (arr[j] <= 0) {
            arr[j] += 26;
            arr[j + 1]--;
        }
    }
    string result;
    for (int j = arr.size() - 1; j >= 0; j--) {
        if (arr[j] > 0)
            result += char('A' + arr[j] - 1);
    }
    return result;
}