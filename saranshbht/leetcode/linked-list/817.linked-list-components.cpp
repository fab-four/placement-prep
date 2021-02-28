/*
 * @author: Saransh Bhatia
 * @user  : saranshbht
 * Link   : https://leetcode.com/problems/linked-list-components/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  int numComponents(ListNode *head, vector<int> &G) {
    unordered_set<int> st(G.begin(), G.end());
    ListNode *current = head;
    bool flag = false;
    int count = 0;
    while (current) {
      if (st.count(current->val)) {
        if (!flag)
          flag = true;
      } else {
        if (flag) {
          flag = false;
          count++;
        }
      }
      current = current->next;
    }
    if (flag)
      count++;
    return count;
  }
};