// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

constexpr int mmax = numeric_limits<int>::max();

bool helper(Node *root, int min_range = 0, int max_range = mmax) {
  if (root == nullptr) {
    return false;
  }
  if (min_range == max_range) {
    return true;
  }
  return helper(root->left, min_range, root->data - 1) ||
         helper(root->right, root->data + 1, max_range);
}

bool isDeadEnd(Node *root) { return helper(root, 1); }
