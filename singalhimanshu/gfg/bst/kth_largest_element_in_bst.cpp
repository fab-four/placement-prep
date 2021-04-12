// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#

/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
public:
  int kthLargest(Node *root, int K) {
    int res = -1;
    KthLargestElementHelper(root, res, K);
    return res;
  }

  void KthLargestElementHelper(Node *root, int &res, int &K) {
    if (root == nullptr) {
      return;
    }
    KthLargestElementHelper(root->right, res, K);
    K--;
    if (K == 0) {
      res = root->data;
      return;
    }
    KthLargestElementHelper(root->left, res, K);
  }
};
