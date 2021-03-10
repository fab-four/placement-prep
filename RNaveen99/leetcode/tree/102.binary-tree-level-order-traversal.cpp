/**
 * Author: Naveen Rohilla
 * User  : RNaveen99
 * Link  : https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        vector<int> currentLevel;
        if (!root) {
            return traversal;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()) {
            TreeNode* root = q.front();
            q.pop();
            
            if (root == NULL) {
                traversal.push_back(currentLevel);
                currentLevel.resize(0);
                if (q.size()) {
                    q.push(NULL);
                }
            } else {
                currentLevel.push_back(root -> val);
                if (root -> left) {
                    q.push(root -> left);
                }
                if (root -> right) {
                    q.push(root -> right);
                }
            }
        }
        return traversal;
    }
};
