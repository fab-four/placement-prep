/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzag;

  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return zigzag;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        int direction = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            while (size > 0) {
                TreeNode *temp = q.front();
                q.pop();
                level.emplace_back(temp->val);

                if (temp->left) {
                    q.emplace(temp->left);
                }
                if (temp->right) {
                    q.emplace(temp->right);
                }
                size--;
            }
            if (direction) {
                reverse(level.begin(), level.end());
            }
            zigzag.emplace_back(level);
            direction ^= 1;
        }
        return zigzag;
    }
};