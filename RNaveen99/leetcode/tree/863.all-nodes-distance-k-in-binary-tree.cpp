/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// converted into undirected graph & perform BFS
class Solution {
    unordered_map<TreeNode *, TreeNode *> m;
    unordered_set<TreeNode *> visited;

  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        dfs(root, nullptr);
        queue<TreeNode *> q;
        q.emplace(target);
        visited.emplace(target);
        vector<int> ans;
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                TreeNode *front = q.front();
                q.pop();
                if (distance == k) {
                    ans.emplace_back(front->val);
                }
                if (front->left && visited.count(front->left) == 0) {
                    q.emplace(front->left);
                    visited.emplace(front->left);
                }
                if (front->right && visited.count(front->right) == 0) {
                    q.emplace(front->right);
                    visited.emplace(front->right);
                }
                if (m[front] && visited.count(m[front]) == 0) {
                    q.emplace(m[front]);
                    visited.emplace(m[front]);
                }
            }
            distance++;
        }
        return ans;
    }
    void dfs(TreeNode *root, TreeNode *parent) {
        if (!root)
            return;
        m[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};