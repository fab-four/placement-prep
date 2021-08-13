/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

enum class State { NOT_COV, COV, HAS_CAM };

class Solution {
public:
  // Time Complexity: O(n)
  // Space Complexity: O(1)
  int minCameraCover(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int cam = 0;
    State root_state = dfs(root, nullptr, cam);
    return root_state == State::NOT_COV ? cam + 1 : cam;
  }

  State dfs(TreeNode *cur, TreeNode *parent, int &cam) {
    if (cur == nullptr) {
      return State::COV;
    }
    State left_state = dfs(cur->left, cur, cam);
    State right_state = dfs(cur->right, cur, cam);
    if (left_state == State::NOT_COV || right_state == State::NOT_COV) {
      cam++;
      return State::HAS_CAM;
    }
    if (left_state == State::HAS_CAM || right_state == State::HAS_CAM) {
      return State::COV;
    }
    return State::NOT_COV;
  }
};
