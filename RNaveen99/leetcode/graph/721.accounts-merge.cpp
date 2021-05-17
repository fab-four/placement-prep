/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/accounts-merge/
 */

// More resource - https://leetcode.com/problems/accounts-merge/discuss/109157/JavaC++-Union-Find/241144
// finding connected components
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        map<string, vector<int>> email_to_account_number = buildGraph(accounts);
        vector<vector<string>> result;
        vector<bool> visited_account_number(accounts.size(), false);
        for (int i = 0; i < accounts.size(); i++) {
            if (visited_account_number[i]) {
                continue;
            }
            set<string> emails;
            dfs(i, accounts, email_to_account_number, visited_account_number, emails);
            vector<string> temp(begin(emails), end(emails));
            temp.insert(begin(temp), accounts[i][0]);
            result.push_back(move(temp));
        }
        return result;
    }

    map<string, vector<int>> buildGraph(const vector<vector<string>> &accounts) {
        map<string, vector<int>> email_to_account_number;
        for (int account_number = 0; account_number < accounts.size(); account_number++) {
            for (int email_index = 1; email_index < accounts[account_number].size(); email_index++) {
                string email = accounts[account_number][email_index];
                email_to_account_number[email].emplace_back(account_number);
            }
        }
        return email_to_account_number;
    }

    void dfs(int account_number, const vector<vector<string>> &accounts,
             map<string, vector<int>> &email_to_account_number, vector<bool> &visited_account_number,
             set<string> &emails) {
        if (visited_account_number[account_number]) {
            return;
        }
        visited_account_number[account_number] = true;
        for (int i = 1; i < accounts[account_number].size(); i++) {
            string email = accounts[account_number][i];
            emails.insert(email);
            for (int i : email_to_account_number[email]) {
                dfs(i, accounts, email_to_account_number, visited_account_number, emails);
            }
        }
    }
};