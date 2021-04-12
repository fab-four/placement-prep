/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/validate-binary-search-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    bool isValidBST(TreeNode *root) { return isValidBSTutil(root, nullptr, nullptr); }

    bool isValidBSTutil(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) {
            return true;
        }
        if (max && root->val >= max->val) {
            return false;
        }
        if (min && root->val <= min->val) {
            return false;
        }

        return isValidBSTutil(root->left, min, root) && isValidBSTutil(root->right, root, max);
    }
};

class Solution {
  public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.emplace(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (prev && (curr->val <= prev->val)) {
                return false;
            }
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};