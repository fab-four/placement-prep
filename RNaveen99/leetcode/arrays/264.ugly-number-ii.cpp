/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/ugly-number-ii/
 */

class Solution {
  public:
    int nthUglyNumber(int n) {
        set<long> s;
        s.emplace(1);
        n--;
        while (n) {
            long smallest = *s.begin();
            s.emplace(smallest * 2);
            s.emplace(smallest * 3);
            s.emplace(smallest * 5);
            s.erase(smallest);
            n--;
        }
        return *s.begin();
    }
};

class Solution {
  public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        vector<int> result(n);
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = min({result[idx2] * 2, result[idx3] * 3, result[idx5] * 5});
            if (result[i] == result[idx2] * 2) {
                idx2++;
            }
            if (result[i] == result[idx3] * 3) {
                idx3++;
            }
            if (result[i] == result[idx5] * 5) {
                idx5++;
            }
        }
        return result[n - 1];
    }
};