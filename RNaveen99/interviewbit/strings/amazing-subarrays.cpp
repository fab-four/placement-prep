/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/amazing-subarrays/
 */

bool isVowel(char c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}

int solve(string A) {
    int count = 0;
    for (int i = 0; i < A.length(); ++i) {
        if (isVowel(A[i])) {
            count += (A.length() - i);
            count %= 10003;
        }
    }
    return count;
}