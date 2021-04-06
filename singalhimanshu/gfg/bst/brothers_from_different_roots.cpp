// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1#

// User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
  int data;
  Node* left, *right;
};*/

bool search(Node *root, int target) {
  if (root == nullptr) {
    return false;
  }
  if (root->data == target) {
    return true;
  }
  if (root->data > target) {
    return search(root->left, target);
  }
  return search(root->right, target);
}

// You are required to complete this function
int countPairs(Node *root1, Node *root2, int x) {
  if (root1 == nullptr) {
    return 0;
  }
  int count = 0;
  if (search(root2, x - root1->data)) {
    count++;
  }
  count += countPairs(root1->left, root2, x);
  count += countPairs(root1->right, root2, x);
  return count;
}
