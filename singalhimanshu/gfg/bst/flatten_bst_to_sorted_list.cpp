// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/

#include <iostream>
using namespace std;

class BSTNode {
public:
  BSTNode *left;
  BSTNode *right;
  int data;
  BSTNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BST {
public:
  BST() : root(nullptr) {}
  void insert(int data);
  void insertHelper(int data, BSTNode *temp);

  BSTNode *root;
};

void BST::insert(int data) {
  if (root == nullptr) {
    root = new BSTNode(data);
    return;
  }
  insertHelper(data, root);
}

void BST::insertHelper(int data, BSTNode *temp) {
  if (temp == nullptr) {
    return;
  }
  if (data > temp->data) {
    if (temp->right == nullptr) {
      temp->right = new BSTNode(data);
    } else {
      insertHelper(data, temp->right);
    }
  } else {
    if (temp->left == nullptr) {
      temp->left = new BSTNode(data);
    } else {
      insertHelper(data, temp->left);
    }
  }
}

class LinkedList {
public:
  BSTNode *head;
  BSTNode *tail;
  LinkedList() : head(nullptr), tail(nullptr) {}
};

LinkedList flatten(BSTNode *root) {
  LinkedList l;
  if (root == nullptr) {
    return l;
  }
  int data = root->data;
  if (root->left == nullptr && root->right == nullptr) {
    l.head = root;
    l.tail = root;
    return l;
  }
  if (root->left && root->right == nullptr) {
    LinkedList left_list = flatten(root->left);
    left_list.tail->right = root;
    l.head = left_list.head;
    l.tail = root;
    return l;
  }
  if (root->left == nullptr && root->right) {
    LinkedList right_list = flatten(root->right);
    root->right = right_list.head;
    l.head = root;
    l.tail = right_list.tail;
  }
  LinkedList left_list = flatten(root->left);
  LinkedList right_list = flatten(root->right);
  left_list.tail->right = root;
  root->right = right_list.head;
  l.head = left_list.head;
  l.tail = right_list.tail;
  return l;
}

int main() {
  BST *bst = new BST();
  bst->insert(5);
  bst->insert(3);
  bst->insert(7);
  bst->insert(1);
  bst->insert(6);
  bst->insert(8);
  bst->insert(-1);
  LinkedList l = flatten(bst->root);
  BSTNode *temp = l.head;
  while (temp) {
    cout << temp->data << "->";
    temp = temp->right;
  }
  cout << '\n';
  return 0;
}
