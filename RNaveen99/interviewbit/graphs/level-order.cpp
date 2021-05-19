/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/level-order/
 */

void buildVector(TreeNode *root, int depth, vector<vector<int>> &ret) {
    if (root == NULL)
        return;
    if (ret.size() == depth)
        ret.push_back(vector<int>());
    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1, ret);
    buildVector(root->right, depth + 1, ret);
}

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    buildVector(root, 0, ret);
    return ret;
}