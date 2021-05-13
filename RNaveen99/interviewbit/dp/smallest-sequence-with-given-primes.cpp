/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
 */

vector<int> Solution::solve(int A, int B, int C, int D) {

    vector<int> numbers;

    if (D == 0)
        return numbers;

    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);

    while (!st.empty()) {
        int curr = *st.begin();
        st.erase(st.begin());
        numbers.push_back(curr);
        if (numbers.size() == D)
            break;
        int p1 = curr * A;
        int p2 = curr * B;
        int p3 = curr * C;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return numbers;
}

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    res.push_back(1);
    int iA = 0, iB = 0, iC = 0;

    for (int i = 0; i < D; i++) {
        int nextA = res[iA] * A;
        int nextB = res[iB] * B;
        int nextC = res[iC] * C;
        int nextN = min(nextA, min(nextB, nextC));

        if (nextN == nextA)
            iA++;

        if (nextN == nextB)
            iB++;

        if (nextN == nextC)
            iC++;

        res.push_back(nextN);
    }

    // res.pop_front();
    vector<int> v;
    for (int i = 0; i < D; i++) {
        v.push_back(res[i + 1]);
    }

    return v;
}