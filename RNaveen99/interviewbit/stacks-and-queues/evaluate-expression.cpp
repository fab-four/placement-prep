/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/evaluate-expression/
 */

bool isOperator(string s) { return s == "+" || s == "-" || s == "*" || s == "/"; }

int Solution::evalRPN(vector<string> &arr) {
    stack<int> st;
    for (auto ele : arr) {
        if (isOperator(ele)) {
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            if (ele == "+") {
                st.push(x + y);
            } else if (ele == "-") {
                st.push(x - y);
            } else if (ele == "*") {
                st.push(x * y);
            } else if (ele == "/") {
                st.push(x / y);
            }
        } else {
            st.push(stoi(ele));
        }
    }
    return st.top();
}