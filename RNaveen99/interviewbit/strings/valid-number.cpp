/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/valid-number/
 */

// trim beginning and ending spaces
// format : (spaces:ignore)(sign:optional)(decimal:compulsory)
// (dot)(number:compulsory)
// (e)(-/+:optional)(number:compulsory)

int isNumber(const string A) {

    int i = 0;
    int n = A.length() - 1;

    // trim spaces
    while (i <= n && A[i] == ' ') {
        i++;
    }
    while (n >= 0 && A[n] == ' ') {
        n--;
    }

    // optional + or - : if comes, number is compulsory
    if (i <= n && (A[i] == '+' || A[i] == '-')) {
        if (i + 1 <= n && (A[i + 1] >= '0' && A[i + 1] <= '9')) {
            i++;
        } else {
            return 0;
        }
    }

    // decimals
    while (i <= n && A[i] >= '0' && A[i] <= '9') {
        i++;
    }

    // optional dot : if comes, atleast one number is compulosry
    if (i <= n && A[i] == '.') {
        if (i + 1 <= n && (A[i + 1] >= '0' && A[i + 1] <= '9')) {
            i++;
            while (i <= n && A[i] >= '0' && A[i] <= '9') {
                i++;
            }
        } else {
            return 0;
        }
    }

    // optional e : if comes, format is : e(+/- : optional)(digit)(digits)*
    if (i <= n && A[i] == 'e') {

        if (i + 1 <= n && (A[i + 1] == '+' || A[i + 1] == '-')) {
            i++;
        }

        if (i + 1 <= n && (A[i + 1] >= '0' && A[i + 1] <= '9')) {
            i++;
        } else {
            return 0;
        }
        while (i <= n && A[i] >= '0' && A[i] <= '9') {
            i++;
        }
    }

    if (i == n + 1) {
        return 1;
    } else {
        return 0;
    }
}