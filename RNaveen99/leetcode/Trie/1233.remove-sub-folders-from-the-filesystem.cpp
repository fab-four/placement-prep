/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
 */

class TrieNode {
  public:
    string folderFormed;
    unordered_map<string, TrieNode *> children;

    TrieNode() { folderFormed = ""; }
    ~TrieNode() {
        for (auto child : children) {
            delete child.second;
        }
    }
};
class Solution {
    TrieNode *root;
    vector<string> result;

  public:
    vector<string> removeSubfolders(vector<string> &folders) {
        buildTrieFromWords(folders);
        dfs(root);
        return result;
    }
    void buildTrieFromWords(vector<string> &folders) {
        root = new TrieNode();
        for (string folder : folders) {
            TrieNode *itr = root;
            string name;
            for (int i = 0; i <= folder.size(); i++) {
                if (i == folder.size() || folder[i] == '/') {
                    if (name.size()) {
                        if (itr->children.find(name) == itr->children.end()) {
                            itr->children[name] = new TrieNode();
                        }
                        itr = itr->children[name];
                        name.clear();
                        if (i == folder.size()) {
                            itr->folderFormed = folder;
                        }
                    }
                } else {
                    name += folder[i];
                }
            }
        }
    }
    void dfs(TrieNode *_root) {
        for (auto itr = _root->children.begin(); itr != _root->children.end(); itr++) {
            if (itr->second->folderFormed.size()) {
                result.emplace_back(itr->second->folderFormed);
            } else {
                dfs(itr->second);
            }
        }
    }
};

// if result is empty
// parent at back is not the parent of `ele` by comparing
// If the entire parent matches `ele` check if last folder name in parent does not match the folder of same
// depth in `ele`. for cases like `/a/b, /a/bc`.

class Solution {
  public:
    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (string ele : folder) {
            if (result.empty()) {
                result.emplace_back(ele);
            } else if (result.back().compare(0, result.back().size(), ele, 0, result.back().size()) != 0) {
                result.emplace_back(ele);
            } else if (ele[result.back().size()] != '/') {
                result.emplace_back(ele);
            }
        }
        return result;
    }
};