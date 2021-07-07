/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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
        if (!root) {
            s.push_back('#');
            s.push_back(',');
            return;
        }

        s += to_string(root->val) + ',';
        serializeUtil(root->left, s);
        serializeUtil(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        queue<string> q;
        string item;
        while (getline(ss, item, ',')) {
            q.emplace(item);
        }
        return deserializeUtil(q);
    }
    TreeNode *deserializeUtil(queue<string> &q) {
        if (q.empty()) {
            return nullptr;
        }

        string value = q.front();
        q.pop();

        if (value == "#") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(value));
        root->left = deserializeUtil(q);
        root->right = deserializeUtil(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));