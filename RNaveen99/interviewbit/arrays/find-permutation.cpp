/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/find-permutation/
 */
// As I denotes the next number should be larger, we need to substitute smallest remaining number
// from our set corresponding to subsequent I as it automatically makes the next element to be
// larger.

// Similar things will happens with character D, we need to substitute the largest remaining number
// from our set.

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B);
    int a = 1, b = B;
    for (int i = 0; i < A.size(); i++)
        ans[i] = A[i] == 'I' ? a++ : b--;
    ans[B - 1] = a;
    return ans;
}

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    int D = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == 'D')
            D++;
    }
    int I = D + 1;

    ans.push_back(I);
    I++;

    for (int i = 0; i < A.length(); i++) {
        if (A[i] == 'D') {
            ans.push_back(D);
            D--;
        } else {
            ans.push_back(I);
            I++;
        }
    }
    return ans;
}