// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

vector<int> diagonal(Node *root) {
  if (root == nullptr) {
    return {};
  }
  Node *cur = root;
  queue<Node *> q;
  q.push(cur);
  vector<int> diagonal_trav;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    while (cur) {
      if (cur->left) {
        q.push(cur->left);
      }
      diagonal_trav.emplace_back(cur->data);
      cur = cur->right;
    }
  }
  return diagonal_trav;
}