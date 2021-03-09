// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

int toSumTreeRec(Node *node) {
  if (node == nullptr) {
    return 0;
  }
  int left_sum = toSumTreeRec(node->left);
  int right_sum = toSumTreeRec(node->right);
  int temp = node->data;
  node->data = left_sum + right_sum;
  return temp + node->data;
}

// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
void toSumTree(Node *node) {
  if (node == nullptr) {
    return;
  }
  toSumTreeRec(node);
}