// @author: Himanshu
// @user: singalhimanshu
// Link:
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector<int> bottomView(Node *root) {
  if (root == nullptr) {
    return {};
  }
  // {vertical_height, data}
  map<int, int> mp;
  Node *cur = root;
  queue<pair<int, Node *>> q;
  q.push({0, cur});
  while (!q.empty()) {
    cur = q.front().second;
    int h = q.front().first;
    q.pop();
    mp[h] = cur->data;
    if (cur->left) {
      q.push({h - 1, cur->left});
    }
    if (cur->right) {
      q.push({h + 1, cur->right});
    }
  }
  vector<int> bottom_view;
  bottom_view.reserve(mp.size());
  for (const auto &ele : mp) {
    bottom_view.emplace_back(ele.second);
  }
  return bottom_view;
}