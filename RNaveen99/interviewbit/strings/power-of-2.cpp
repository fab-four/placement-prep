/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/power-of-2/
 */

int isPowerOf2(char *str) {
    int len_str = strlen(str);
    // sum stores the intermediate dividend while dividing.
    int num = 0;

    // if the input is "1" then return 0 because 2^k = 1 where k >= 1 and here k = 0
    if (len_str == 1 && str[len_str - 1] == '1')
        return 0;

    // Divide the number until it gets reduced to 1
    // If we are successfully able to reduce the number to 1 it means input string is power of two.
    // If in between an odd number appears at the end it means string is not divisible by two hence not a
    //  power of 2.
    while (len_str != 1 || str[len_str - 1] != '1') {

        // if the last digit is odd then string is not divisible by 2 hence not a power of two, return 0.
        if ((str[len_str - 1] - '0') % 2 == 1)
            return 0;

        // divide the whole string by 2. i is used to track index in current number. j is used to
        // track index for next iteration.
        for (int i = 0, j = 0; i < len_str; i++) {
            num = num * 10 + str[i] - '0';

            // if num < 2 then we have to take another digit to the right of A[i] to make it bigger than
            // A[i]. E. g. 214 / 2 --> 107
            if (num < 2) {

                // if it's not the first index. E.g 214 then we have to include 0.
                if (i != 0) {
                    str[j] = '0';
                    j++;
                }

                // for eg. "124" we will not write 064 so if it is the first index just ignore
                continue;
            }

            str[j] = (int)(num / 2) + '0';
            j++;
            num = (num) - (num / 2) * 2;
        }
        // After every division by 2 the length of string is changed.
        len_str = j;
    }

    // if the string reaches to 1 then the str is a power of 2.
    return 1;
}