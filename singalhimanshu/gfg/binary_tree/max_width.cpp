// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

/*  Structure of a Binary Tree
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
/* Function to get the maximum width of a binary tree*/

int getMaxWidth(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  Node *cur = root;
  size_t max_width = 1;
  queue<Node *> q;
  q.push(cur);
  while (!q.empty()) {
    auto q_size = q.size();
    max_width = max(max_width, q_size);
    for (size_t i = 0; i < q_size; i++) {
      cur = q.front();
      q.pop();
      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }
  }
  return max_width;
}