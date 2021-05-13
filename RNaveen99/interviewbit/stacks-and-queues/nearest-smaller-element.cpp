/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/nearest-smaller-element/
 */

// 1. Create a new empty stack "st"
// 2. Iterate over array A, where i goes from 0 to size(A) - 1.
//      a) We are looking for value just smaller than A[i].
//         So keep popping from st till elements in st.top() >= A[i] or st becomes empty.
//      b) If st is non empty, then the top element is our previous element.
//         Else the previous element does not exist.
//      c) push A[i] onto "st"

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    ans.resize(A.size());

    stack<int> st;

    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i])
            st.pop();
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}