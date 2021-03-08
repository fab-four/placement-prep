// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

/*
struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};
*/

// This function should return head to the DLL
class Solution {
private:
  Node *head = nullptr;
  Node *prev = nullptr;

public:
  Node *bToDLL(Node *root) {
    if (root == nullptr) {
      return root;
    }
    bToDLL(root->left);
    if (prev == nullptr) {
      head = root;
    } else {
      root->left = prev;
      prev->right = root;
    }
    prev = root;
    bToDLL(root->right);
    return head;
  }
};
