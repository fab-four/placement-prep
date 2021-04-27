/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/add-binary-strings/
 */

class Solution {
  public:
    string addBinary(string a, string b) {
        string ans = "";
        int ansLen = 0, carry = 0, sum;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            if (i >= 0)
                sum += (a[i] - '0');
            if (j >= 0)
                sum += (b[j] - '0');
            ans.push_back((char)('0' + sum % 2));
            carry = sum / 2;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
