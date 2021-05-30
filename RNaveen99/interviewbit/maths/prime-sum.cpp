/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/prime-sum/
 */

vector<int> Solution::primesum(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++)
        if (isPrime[p])
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;

    vector<int> B;

    for (int i = 0; i < n; i++) {
        if (isPrime[i] && isPrime[n - i]) {
            B.push_back(i);
            B.push_back(n - i);
            return B;
        }
    }
    return B;
}