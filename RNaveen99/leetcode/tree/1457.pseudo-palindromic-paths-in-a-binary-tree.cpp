/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
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

// BFS
class Solution {
  public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int count = 0;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int path = front.second;
            path = path ^ (1 << front.first->val);
            if (!front.first->left && !front.first->right) {
                if ((path & (path - 1)) == 0) {
                    count++;
                }
            } else {
                if (front.first->left) {
                    q.emplace(front.first->left, path);
                }
                if (front.first->right) {
                    q.emplace(front.first->right, path);
                }
            }
        }
        return count;
    }
};

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
    int count = 0;

  public:
    int pseudoPalindromicPaths(TreeNode *root) {
        util(root, 0);
        return count;
    }
    void util(TreeNode *root, int path) {
        if (!root)
            return;
        path = path ^ (1 << root->val);
        if (!root->left && !root->right) {
            if ((path & (path - 1)) == 0) {
                count++;
            }
        }
        util(root->left, path);
        util(root->right, path);
    }
};