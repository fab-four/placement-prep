// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
  int ladderLength(string begin_word, string end_word,
                   vector<string> &word_list) {
    unordered_map<string, bool> vis;
    queue<string> q;
    int moves = 1;
    q.push(begin_word);
    vis[begin_word] = true;
    while (!q.empty()) {
      auto q_size = q.size();
      for (size_t i = 0; i < q_size; i++) {
        string cur = q.front();
        if (cur == end_word) {
          return moves;
        }
        q.pop();
        for (const auto &word : word_list) {
          if (hasOneWordDiff(cur, word) && !vis[word]) {
            vis[word] = true;
            q.push(word);
          }
        }
      }
      moves++;
    }
    return 0;
  }

  bool hasOneWordDiff(const string &str1, const string &str2) {
    if (str1.size() != str2.size()) {
      return false;
    }
    bool once = false;
    for (size_t i = 0; i < str1.size(); i++) {
      if (str1[i] != str2[i]) {
        if (once) {
          return false;
        }
        once = true;
      }
    }
    return once;
  }
};
