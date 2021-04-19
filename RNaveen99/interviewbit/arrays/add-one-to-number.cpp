/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/add-one-to-number/
 */

vector<int> Solution::plusOne(vector<int> &A) {
    int size = A.size();
    int carry = 1;
    vector<int> B;
    int index = 0;

    while (index < size && A[index] == 0)
        index++;

    for (int i = size - 1; i >= index; i--) {
        int digit = A[i];
        if (carry > 0) {
            if (A[i] == 9) {
                digit = 0;
                carry = 1;
            } else {
                digit = digit + 1;
                carry = 0;
            }
        }
        B.push_back(digit);
    }

    if (carry)
        B.push_back(1);

    reverse(B.begin(), B.end());
    return B;
}