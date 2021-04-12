// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/common-elements1132/1

class Solution {
public:
  vector<int> commonElements(int A[], int B[], int C[], int n1, int n2,
                             int n3) {
    vector<int> common_elements;
    int i = 0, j = 0, k = 0;
    int mn = 0;
    while (i < n1 && j < n2 && k < n3) {
      if (A[i] == B[j] && B[j] == C[k]) {
        if (mn != A[i]) {
          mn = A[i];
          common_elements.emplace_back(A[i]);
        }
        i++;
        continue;
      }
      int mn = min(A[i], min(B[j], C[k]));
      if (mn == A[i]) {
        i++;
      } else if (mn == B[j]) {
        j++;
      } else {
        k++;
      }
    }
    return common_elements;
  }
};
