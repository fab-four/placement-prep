/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/seats/
 */

#define MOD 10000003

class Solution {
  public:
    int seats(string str) {
        int N = str.size();
        vector<int> Pos;
        for (int i = 0; i < N; ++i) {
            if (str[i] == 'x') {
                Pos.push_back(i);
            }
        }
        int n = Pos.size();
        if (n == 0)
            return 0;
        int mid = n / 2;
        int median = n & 1 ? Pos[mid] : (Pos[mid] + Pos[mid - 1]) / 2;
        int ans = 0;
        int empty = str[median] == 'x' ? median - 1 : median;
        for (int i = median - 1; i >= 0; --i) {
            if (str[i] == 'x') {
                ans += empty - (i);
                if (ans >= MOD)
                    ans %= MOD;
                empty--;
            }
        }

        empty = median + 1;
        for (int i = median + 1; i < N; ++i) {
            if (str[i] == 'x') {
                ans += (i)-empty;
                if (ans >= MOD)
                    ans %= MOD;
                empty++;
            }
        }
        return ans;
    }
};