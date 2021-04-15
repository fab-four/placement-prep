// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/accounts-merge/

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    map<string, vector<int>> email_to_account = buildGraph(accounts);
    vector<vector<string>> result;
    vector<bool> vis(accounts.size(), false);
    for (int i = 0; i < accounts.size(); i++) {
      if (vis[i]) {
        continue;
      }
      set<string> emails;
      dfs(i, accounts, email_to_account, vis, emails);
      vector<string> temp(begin(emails), end(emails));
      temp.insert(begin(temp), accounts[i][0]);
      result.push_back(move(temp));
    }
    return result;
  }

  map<string, vector<int>> buildGraph(const vector<vector<string>> &accounts) {
    map<string, vector<int>> email_to_account;
    for (int acc_idx = 0; acc_idx < accounts.size(); acc_idx++) {
      for (int email_idx = 1; email_idx < accounts[acc_idx].size();
           email_idx++) {
        string email = accounts[acc_idx][email_idx];
        email_to_account[email].emplace_back(acc_idx);
      }
    }
    return email_to_account;
  }

  void dfs(int src, const vector<vector<string>> &accounts,
           map<string, vector<int>> &email_to_account, vector<bool> &vis,
           set<string> &emails) {
    if (vis[src]) {
      return;
    }
    vis[src] = true;
    for (size_t i = 1; i < accounts[src].size(); i++) {
      string email = accounts[src][i];
      emails.insert(email);
      for (const auto &acc_idx : email_to_account[email]) {
        dfs(acc_idx, accounts, email_to_account, vis, emails);
      }
    }
  }
};
