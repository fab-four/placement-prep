// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#

/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
  // Return the Kth smallest element in the given BST
  int KthSmallestElement(Node *root, int K) {
    int res = -1;
    KthSmallestElementHelper(root, res, K);
    return res;
  }

  void KthSmallestElementHelper(Node *root, int &res, int &K) {
    if (root == nullptr) {
      return;
    }
    KthSmallestElementHelper(root->left, res, K);
    K--;
    if (K == 0) {
      res = root->data;
      return;
    }
    KthSmallestElementHelper(root->right, res, K);
  }
};
