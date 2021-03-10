// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/

Node *lca(Node *node, int a, int b) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->data == a || node->data == b) {
    return node;
  }
  Node *left_ans = lca(node->left, a, b);
  Node *right_ans = lca(node->right, a, b);
  if (left_ans && right_ans) {
    return node;
  }
  return left_ans ? left_ans : right_ans;
}

int findDistSingle(Node *node, int target, int dist) {
  if (node == nullptr) {
    return -1;
  }
  if (node->data == target) {
    return dist;
  }
  int left_dist = findDistSingle(node->left, target, dist + 1);
  if (left_dist != -1) {
    return left_dist;
  }
  return findDistSingle(node->right, target, dist + 1);
}

int findDist(Node *root, int a, int b) {
  Node *lca_node = lca(root, a, b);
  int left_dist = findDistSingle(lca_node, a, 0);
  int right_dist = findDistSingle(lca_node, b, 0);
  return left_dist + right_dist;
}