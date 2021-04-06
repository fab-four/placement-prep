// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/largest-bst/1#

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST

constexpr int mmax = numeric_limits<int>::max();
constexpr int mmin = numeric_limits<int>::min();

struct Entry {
  bool is_bst;
  int bst_size;
  int mn;
  int mx;
  Entry(bool is_bst, int bst_size, int mn = mmin, int mx = mmax)
      : is_bst(is_bst), bst_size(bst_size), mn(mn), mx(mx) {}
};

Entry getMaxSizeEntry(Node *root) {
  if (root == nullptr) {
    return Entry(true, 0, mmax, mmin);
  }
  Entry left_entry = getMaxSizeEntry(root->left);
  Entry right_entry = getMaxSizeEntry(root->right);
  if (left_entry.is_bst == false || right_entry.is_bst == false ||
      (root->data <= left_entry.mx || root->data >= right_entry.mn)) {
    int max_bst_size = max(left_entry.bst_size, right_entry.bst_size);
    return Entry(false, max_bst_size);
  }
  int left_min = root->left ? left_entry.mn : root->data;
  int right_max = root->right ? right_entry.mx : root->data;
  return Entry(true, left_entry.bst_size + right_entry.bst_size + 1, left_min,
               right_max);
}

int largestBst(Node *root) {
  auto max_size_entry = getMaxSizeEntry(root);
  return max_size_entry.bst_size;
}
