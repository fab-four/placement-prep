// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#

bool isHeap(Node *tree) {
  if (tree == nullptr) {
    return true;
  }
  if (tree->left && tree->data < tree->left->data) {
    return false;
  }
  if (tree->right && tree->data < tree->right->data) {
    return false;
  }
  return isHeap(tree->left) && isHeap(tree->right);
}
