/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    queue<TreeNode *> q;

  public:
    bool isSameTree(TreeNode *s1, TreeNode *s2) {
        if (!check(s1, s2))
            return false;
        while (!q.empty()) {
            s1 = q.front();
            q.pop();
            s2 = q.front();
            q.pop();

            if (s1->val != s2->val)
                return false;

            if (!check(s1->left, s2->left)) {
                return false;
            }
            if (!check(s1->right, s2->right)) {
                return false;
            }
        }
        return true;
    }
    bool check(TreeNode *s1, TreeNode *s2) {
        if (!s1 && !s2)
            return true;
        if (!s1 || !s2)
            return false;
        q.emplace(s1);
        q.emplace(s2);
        return true;
    }
};