/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *prev = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.emplace(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (prev && !first && prev->val >= curr->val) {
                // The first element is always larger than its next one
                first = prev;
            }
            if (first && prev->val >= curr->val) {
                // The second element is always smaller than its previous one.
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};