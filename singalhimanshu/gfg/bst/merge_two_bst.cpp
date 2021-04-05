// @author: Himanshu
// @user: singalhimanshu
// Link: https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int data;
  TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

void inorderTrav(TreeNode *root, vector<int> &inorder) {
  if (root == nullptr) {
    return;
  }
  inorderTrav(root->left, inorder);
  inorder.emplace_back(root->data);
  inorderTrav(root->right, inorder);
}

TreeNode *buildBSTFromInorder(int left, int right, const vector<int> &inorder) {
  if (left > right) {
    return nullptr;
  }
  int mid = (left + right) / 2;
  TreeNode *root = new TreeNode(inorder[mid]);
  root->left = buildBSTFromInorder(left, mid - 1, inorder);
  root->right = buildBSTFromInorder(mid + 1, right, inorder);
  return root;
}

vector<int> mergeTwoArrays(const vector<int> v1, const vector<int> v2) {
  size_t i1 = 0, i2 = 0;
  vector<int> merged_arrays;
  merged_arrays.reserve(v1.size() + v2.size());
  while (i1 < v1.size() && i2 < v2.size()) {
    if (v1[i1] <= v2[i2]) {
      merged_arrays.emplace_back(v1[i1]);
      i1++;
    } else {
      merged_arrays.emplace_back(v2[i2]);
      i2++;
    }
  }
  while (i1 < v1.size()) {
    merged_arrays.emplace_back(v1[i1]);
    i1++;
  }
  while (i2 < v2.size()) {
    merged_arrays.emplace_back(v2[i2]);
    i2++;
  }
  return merged_arrays;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2) {
  if (root1 == nullptr || root2 == nullptr) {
    return nullptr;
  }
  vector<int> inorder1;
  vector<int> inorder2;
  inorderTrav(root1, inorder1);
  inorderTrav(root2, inorder2);
  auto sorted_arr = mergeTwoArrays(inorder1, inorder2);
  return buildBSTFromInorder(0, sorted_arr.size() - 1, sorted_arr);
}
