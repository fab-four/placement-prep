/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/serialize-and-deserialize-bst/
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
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s;
        serializeUtil(root, s);
        return s;
    }
    void serializeUtil(TreeNode *root, string &s) {
        if (!root)
            return;
        s += to_string(root->val) + ',';
        serializeUtil(root->left, s);
        serializeUtil(root->right, s);
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        queue<int> q;
        string item;
        while (getline(ss, item, ',')) {
            q.emplace(stoi(item));
        }
        return deserializeUtil(q, INT_MIN, INT_MAX);
    }
    TreeNode *deserializeUtil(queue<int> &q, int lower, int upper) {
        if (q.empty()) {
            return nullptr;
        }
        int value = q.front();
        if (value < lower || value > upper) {
            return nullptr;
        }
        q.pop();
        TreeNode *root = new TreeNode(value);
        root->left = deserializeUtil(q, lower, value);
        root->right = deserializeUtil(q, value, upper);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
