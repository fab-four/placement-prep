/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        // postorderRecursive(root, postorder);
        postorderIter(root, postorder);
        return postorder;
    }
    void postorderRecursive(TreeNode *root, vector<int> &postorder) {
        if (root == NULL) {
            return;
        }
        postorderRecursive(root->left, postorder);
        postorderRecursive(root->right, postorder);
        postorder.push_back(root->val);
    }
    // Not a postorder .... but gives correct output...
    // compute root, right, left and then reverse it to get left, right, root
    void postorderIter(TreeNode *root, vector<int> &postorder) {
        stack<TreeNode *> s;

        while (root || !s.empty()) {
            while (root) {
                postorder.push_back(root->val);
                s.push(root);
                root = root->right;
            }
            root = s.top();
            root = root->left;
            s.pop();
        }
        reverse(postorder.begin(), postorder.end());
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
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        postorderIter(root, postorder);
        return postorder;
    }
    void postorderIter(TreeNode *root, vector<int> &postorder) {
        stack<TreeNode *> s;

        while (root || !s.empty()) {
            while (root) {
                if (root->right) {
                    s.push(root->right);
                }
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->right && !s.empty() && root->right == s.top()) {
                s.pop();
                s.push(root);
                root = root->right;
            } else {
                postorder.push_back(root->val);
                root = nullptr;
            }
        }
    }
};