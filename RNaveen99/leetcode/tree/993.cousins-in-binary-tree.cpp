/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode *root, int x, int y) {
        queue<TreeNode *> q;
        q.emplace(root);
        bool xFound = false, yFound = false;
        while (!q.empty()) {
            int size = q.size();

            while (size > 0) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->val == x)
                    xFound = true;
                if (temp->val == y)
                    yFound = true;

                if (temp->left && temp->right) {
                    if (temp->left->val == x && temp->right->val == y) {
                        return false;
                    }
                    if (temp->left->val == y && temp->right->val == x) {
                        return false;
                    }
                }
                if (temp->left) {
                    q.emplace(temp->left);
                }
                if (temp->right) {
                    q.emplace(temp->right);
                }
                size--;
            }
            if (xFound && yFound) {
                return true;
            }
            if (xFound || yFound) {
                return false;
            }
        }
        return false;
    }
};