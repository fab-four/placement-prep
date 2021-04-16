/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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
    map<int, map<int, multiset<int>>> m;
    vector<vector<int>> traversal;

  public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        verticalTraversalUtil(root, 0, 0);
        for (auto ele : m) {
            vector<int> col;
            for (auto j : ele.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            traversal.emplace_back(col);
        }
        return traversal;
    }
    void verticalTraversalUtil(TreeNode *root, int row, int col) {
        if (!root)
            return;

        m[col][row].emplace(root->val);
        verticalTraversalUtil(root->left, row + 1, col - 1);
        verticalTraversalUtil(root->right, row + 1, col + 1);
    }
};