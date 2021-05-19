/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/bulbs/
 */

int Solution::bulbs(vector<int> &arr) {
    int switchFlips = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if ((arr[i] == 1 && (switchFlips & 1)) || (arr[i] == 0 && switchFlips % 2 == 0)) {
            switchFlips++;
        }
    }
    return switchFlips;
}