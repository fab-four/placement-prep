// @author: Himanshu
// @user: singalhimanshu
// Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// function should print the topView of the binary tree
vector<int> topView(struct Node *root) {
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
    int cur_height = q.front().first;
    q.pop();
    if (!mp[cur_height]) {
      mp[cur_height] = cur->data;
    }
    if (cur->left) {
      q.push({cur_height - 1, cur->left});
    }
    if (cur->right) {
      q.push({cur_height + 1, cur->right});
    }
  }
  vector<int> top_view;
  top_view.reserve(mp.size());
  for (const auto &ele : mp) {
    top_view.emplace_back(ele.second);
  }
  return top_view;
}