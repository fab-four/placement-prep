/* The structure of a BST node is as follows:

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

// The function returns the root of the BST (currently rooted at 'root')
// after inserting a new Node with value 'Key' into it.
Node *insert(Node *root, int Key) {
  Node *new_node = new Node(Key);
  if (root == nullptr) {
    return new_node;
  }
  Node *cur = root;
  Node *parent = nullptr;
  while (cur) {
    parent = cur;
    if (cur->data == Key) {
      return root;
    }
    if (Key < cur->data) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }
  if (Key < parent->data) {
    parent->left = new_node;
  } else {
    parent->right = new_node;
  }
  return parent;
}