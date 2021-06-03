/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/find-duplicate-subtrees/
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
    unordered_map<string, vector<TreeNode *>> hash;
    vector<TreeNode *> result;

  public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        findDuplicateUtil(root);
        for (auto ele : hash) {
            if (ele.second.size() > 1) {
                result.emplace_back(ele.second[0]);
            }
        }
        return result;
    }
    string findDuplicateUtil(TreeNode *root) {
        if (!root)
            return "#";
        string left = findDuplicateUtil(root->left);
        string right = findDuplicateUtil(root->right);

        string serialization = to_string(root->val) + "," + left + "," + right;
        hash[serialization].emplace_back(root);
        return serialization;
    }
};