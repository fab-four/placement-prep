// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
vector<int> leftView(Node *root) {
  if (root == nullptr) {
    return {};
  }
  Node *cur = root;
  queue<Node *> q;
  q.push(cur);
  vector<int> left_view;
  while (!q.empty()) {
    auto q_size = q.size();
    for (size_t i = 0; i < q_size; i++) {
      cur = q.front();
      q.pop();
      if (i == 0) {
        left_view.emplace_back(cur->data);
      }
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }
  }
  return left_view;
}
