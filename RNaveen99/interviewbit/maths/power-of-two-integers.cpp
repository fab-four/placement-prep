/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/power-of-two-integers/
 */

int Solution::isPower(int A) {
    if (A <= 1)
        return true;

    int sqrtA = floor(sqrt(A));

    if (sqrtA * sqrtA == A)
        return 1;

    for (int x = 2; x <= sqrtA; x++) {
        unsigned int p = x;
        while (p <= A) {
            p *= x;
            if (p == A)
                return 1;
        }
    }
    return 0;
}

int Solution::isPower(int A) {
    if (A < 2) {
        return 1;
    }
    for (int i = 2; i * i <= A; i++) {
        double x = log(A) / log(i);
        if (x - (int)x < 0.00000001) {
            return true;
        }
    }
    return false;
}