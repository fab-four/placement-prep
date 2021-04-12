/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> set;
        return findTargetUtil(set, root, k);
    }

    bool findTargetUtil(unordered_set<int> &set, TreeNode *root, int k) {
        if (!root) {
            return false;
        }

        int complement = k - root->val;
        if (set.find(complement) != set.end()) {
            return true;
        } else {
            set.emplace(root->val);
        }

        bool left = findTargetUtil(set, root->left, k);
        if (left) {
            return left;
        }
        bool right = findTargetUtil(set, root->right, k);
        if (right) {
            return right;
        }
        return false;
    }
};