/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/compare-version-numbers/
 */

int Solution::compareVersion(string A, string B) {

    int i = 0, j = 0, n = A.size(), m = B.size();

    while (i < n && j < n) {
        string x = "";
        string y = "";

        while (i < n && A[i] == '0')
            i++;

        while (i < n && A[i] != '.') {
            x += A[i];
            i++;
        }

        while (j < m && B[j] == '0')
            j++;

        while (j < m && B[j] != '.') {
            y += B[j];
            j++;
        }

        if (x != y) {
            if (x.length() == y.length())
                return x.compare(y) > 0 ? 1 : -1;
            return x.length() > y.length() ? 1 : -1;
        }

        i++;
        j++;
    }

    while (i < n && A[i] == '0')
        i++;

    while (j < m && B[j] == '0')
        j++;

    if (i >= n && j >= m)
        return 0;

    return i > j ? 1 : -1;
}