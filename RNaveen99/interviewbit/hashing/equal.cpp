/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/equal/
 */

vector<int> Solution::equal(vector<int> &nums) {
    vector<int> out;
    int size = nums.size();
    int A, B, C, D;

    for (A = 0; A < size; A++) {
        for (B = A + 1; B < size; B++) {
            for (C = 0; C < size; C++) {
                for (D = C + 1; D < size; D++) {
                    if (A < C && B != D && B != C && (nums[A] + nums[B] == nums[C] + nums[D])) {
                        return {A, B, C, D};
                    }
                }
            }
        }
    }
    return out;
}

vector<int> Solution::equal(vector<int> &vec) {
    int N = vec.size();
    // With every sum, we store the lexicographically first occuring pair of integers.
    map<int, pair<int, int>> h;
    vector<int> Ans;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {

            int Sum = vec[i] + vec[j];

            if (h.find(Sum) == h.end()) {
                h[Sum] = make_pair(i, j);
                continue;
            }

            pair<int, int> p1 = h[Sum];
            if (p1.first < i && p1.second != i && p1.second != j) {
                vector<int> ans;
                ans.push_back(p1.first);
                ans.push_back(p1.second);
                ans.push_back(i);
                ans.push_back(j);

                if (Ans.size() == 0)
                    Ans = ans;
                else {
                    // compare and assign Ans
                    bool shouldReplace = false;
                    for (int i1 = 0; i1 < Ans.size(); i1++) {
                        if (Ans[i1] < ans[i1])
                            break;
                        if (Ans[i1] > ans[i1]) {
                            shouldReplace = true;
                            break;
                        }
                    }
                    if (shouldReplace)
                        Ans = ans;
                }
            }
        }
    }

    return Ans;
}