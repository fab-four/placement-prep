/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/longest-valid-parentheses/
 */

int Solution::longestValidParentheses(string A) {
    int sol = 0;
    int index = 0;
    stack<int> st;
    st.push(-1);
    while (index < A.size()) {
        if (A[index] == '(') {
            st.push(index);
        } else {
            st.pop();
            if (!st.empty()) {
                sol = max(index - st.top(), sol);
            } else {
                st.push(index);
            }
        }
        index++;
    }
    return sol;
}