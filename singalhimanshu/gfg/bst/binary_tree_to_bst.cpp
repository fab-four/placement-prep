// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
  // The given root is the root of the Binary Tree
  // Return the root of the generated BST
  Node *binaryTreeToBST(Node *root) {
    if (root == nullptr) {
      return nullptr;
    }
    vector<int> in;
    inorder(root, in);
    sort(begin(in), end(in));
    fixBinaryTree(root, in);
    return root;
  }

  void fixBinaryTree(Node *root, const vector<int> &in) {
    if (root == nullptr) {
      return;
    }
    fixBinaryTree(root->left, in);
    root->data = in[m_idx++];
    fixBinaryTree(root->right, in);
  }

  void inorder(Node *root, vector<int> &in) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left, in);
    in.emplace_back(root->data);
    inorder(root->right, in);
  }

private:
  size_t m_idx = 0;
}:
